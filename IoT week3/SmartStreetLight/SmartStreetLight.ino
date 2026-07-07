/*
--------------------------------------
Smart Street Lighting System
ESP32
--------------------------------------
*/

#define LDR_PIN 34
#define PIR_PIN 27
#define LIGHT_PIN 25

int ldrValue;
int motion;

void setup() {

  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);

  pinMode(LIGHT_PIN, OUTPUT);

}

void loop() {

  ldrValue = analogRead(LDR_PIN);

  motion = digitalRead(PIR_PIN);

  Serial.print("Light : ");
  Serial.print(ldrValue);

  Serial.print(" Motion : ");
  Serial.println(motion);

  if (ldrValue < 1500) {

    if (motion == HIGH) {

      digitalWrite(LIGHT_PIN, HIGH);

      Serial.println("Street Light ON");
    }

    else {

      digitalWrite(LIGHT_PIN, LOW);

      Serial.println("No Motion");
    }

  }

  else {

    digitalWrite(LIGHT_PIN, LOW);

    Serial.println("Day Time");
  }

  delay(1000);

}