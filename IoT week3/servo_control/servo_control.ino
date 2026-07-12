/*
-------------------------------------------------------
Project      : Servo Motor Sweep
Author       : Priyanshu Yadav
Roll Number  : 24BCA037
-------------------------------------------------------
*/

#include <Servo.h>

Servo myServo;

const int potPin = A0;
const int buttonPin = 2;

void setup() {

  Serial.begin(9600);

  myServo.attach(9);

  pinMode(buttonPin, INPUT_PULLUP);

}

void loop() {

  int potValue = analogRead(potPin);

  int angle = map(potValue, 0, 1023, 0, 180);

  myServo.write(angle);

  Serial.print("Servo Angle : ");
  Serial.print(angle);
  Serial.println(" Degree");

  // Button Press → Full Sweep
  if (digitalRead(buttonPin) == LOW) {

    Serial.println("Performing Servo Sweep...");

    // 0 → 180
    for (int i = 0; i <= 180; i++) {

      myServo.write(i);
      delay(10);

    }

    // 180 → 0
    for (int i = 180; i >= 0; i--) {

      myServo.write(i);
      delay(10);

    }

  }

  delay(100);

}