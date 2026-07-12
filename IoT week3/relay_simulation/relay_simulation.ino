/*
-------------------------------------------------------
Project      : Relay Controlled AC Simulation
Author       : Priyanshu Yadav
Roll Number  : 24BCA037

Description:
LED simulates an AC appliance controlled through a relay.
-------------------------------------------------------
*/

#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

#define RELAY_LED 25
#define BUTTON_PIN 27

DHT dht(DHTPIN, DHTTYPE);

bool relayState = false;
bool manualOverride = false;
bool lastButtonState = HIGH;

void setup() {

  Serial.begin(115200);

  dht.begin();

  pinMode(RELAY_LED, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  digitalWrite(RELAY_LED, LOW);

}

void loop() {

  float temp = dht.readTemperature();

  if (isnan(temp)) {
    Serial.println("Sensor Error");
    delay(1000);
    return;
  }

  // ---------- Manual Override ----------

  bool buttonState = digitalRead(BUTTON_PIN);

  if (lastButtonState == HIGH && buttonState == LOW) {

    manualOverride = !manualOverride;

    relayState = !relayState;

    digitalWrite(RELAY_LED, relayState);

    Serial.print("MANUAL OVERRIDE | Temp: ");
    Serial.print(temp);
    Serial.print(" C | Relay: ");

    if (relayState)
      Serial.println("ON");
    else
      Serial.println("OFF");

    delay(300);
  }

  lastButtonState = buttonState;

  // ---------- Automatic Mode ----------

  if (!manualOverride) {

    // Turn ON above 32°C
    if (temp > 32 && !relayState) {

      relayState = true;

      digitalWrite(RELAY_LED, HIGH);

      Serial.print("Temp: ");
      Serial.print(temp);
      Serial.println(" C -> Relay ON (AC ON)");

    }

    // Turn OFF below 28°C
    else if (temp < 28 && relayState) {

      relayState = false;

      digitalWrite(RELAY_LED, LOW);

      Serial.print("Temp: ");
      Serial.print(temp);
      Serial.println(" C -> Relay OFF (AC OFF)");

    }

  }

  delay(1000);

}