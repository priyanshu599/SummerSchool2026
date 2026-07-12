/*
-------------------------------------------------------
Project      : Smart Street Light
Author       : Priyanshu Yadav
Roll Number  : 24BCA037

Description:
Smart Street Light using LDR + PIR Sensor on ESP32

Features:
• Daytime -> LED OFF
• Night + Motion -> LED 100% Brightness
• No Motion for 30 sec -> LED 20% Brightness
• Event logging with timestamps
-------------------------------------------------------
*/

#define LDR_PIN    34
#define PIR_PIN    27
#define LIGHT_PIN  25

const int threshold = 1500;

// PWM Configuration
const int pwmChannel = 0;
const int pwmFreq = 5000;
const int pwmResolution = 8;

unsigned long motionTime = 0;
bool motionDetected = false;

void printTime() {

  unsigned long totalSeconds = millis() / 1000;

  int hh = (totalSeconds / 3600) % 24;
  int mm = (totalSeconds / 60) % 60;
  int ss = totalSeconds % 60;

  Serial.print("[");

  if (hh < 10) Serial.print("0");
  Serial.print(hh);

  Serial.print(":");

  if (mm < 10) Serial.print("0");
  Serial.print(mm);

  Serial.print(":");

  if (ss < 10) Serial.print("0");
  Serial.print(ss);

  Serial.print("] ");
}

void setup() {

  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);

  // ESP32 PWM
  ledcSetup(pwmChannel, pwmFreq, pwmResolution);
  ledcAttachPin(LIGHT_PIN, pwmChannel);

  ledcWrite(pwmChannel, 0);

  Serial.println("--------------------------------------");
  Serial.println("Smart Street Lighting System");
  Serial.println("--------------------------------------");

}

void loop() {

  int ldrValue = analogRead(LDR_PIN);
  int motion = digitalRead(PIR_PIN);

  // ---------- DAYTIME ----------
  if (ldrValue > threshold) {

    ledcWrite(pwmChannel, 0);

    motionDetected = false;

    printTime();
    Serial.println("EVENT: Daylight detected - Street Light OFF");

    delay(1000);
    return;
  }

  // ---------- NIGHT ----------
  if (motion == HIGH) {

    ledcWrite(pwmChannel, 255);      // 100% Brightness

    motionDetected = true;

    motionTime = millis();

    printTime();
    Serial.println("EVENT: Motion detected - LED Full Brightness");

  }

  // ---------- NO MOTION ----------
  if (motionDetected) {

    if (millis() - motionTime >= 30000) {

      ledcWrite(pwmChannel, 51);     // 20% Brightness

      motionDetected = false;

      printTime();
      Serial.println("EVENT: No Motion - LED Dimmed to 20%");

    }

  }

}