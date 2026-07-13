/*
-------------------------------------------------------
Project      : ESP32 Bluetooth LED Controller
Author       : Priyanshu Yadav
Roll Number  : 24BCA037
-------------------------------------------------------
*/

#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

const int RED = 25;
const int GREEN = 26;
const int BLUE = 27;

void allOff() {

  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);

}

void setup() {

  Serial.begin(115200);

  SerialBT.begin("ESP32_LED");

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  allOff();

  Serial.println("Bluetooth Ready");
}

void loop() {

  if (SerialBT.available()) {

    char cmd = SerialBT.read();

    Serial.print("Received : ");
    Serial.println(cmd);

    switch (cmd) {

      case 'R':

        allOff();
        digitalWrite(RED, HIGH);

        break;

      case 'G':

        allOff();
        digitalWrite(GREEN, HIGH);

        break;

      case 'B':

        allOff();
        digitalWrite(BLUE, HIGH);

        break;

      case 'X':

        allOff();

        break;

      case 'F':

        for (int i = 0; i < 5; i++) {

          digitalWrite(RED, HIGH);
          digitalWrite(GREEN, HIGH);
          digitalWrite(BLUE, HIGH);

          delay(250);

          allOff();

          delay(250);

        }

        break;

      default:

        Serial.println("Unknown Command");

    }

  }

}