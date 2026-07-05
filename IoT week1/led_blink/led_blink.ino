/*
------------------------------------------------------
Project      : LED Blink
Author       : Priyanshu Yadav
Roll Number  : IoT-029
Date         : July 2026

Description:
LED blink project whose blinking speed is controlled
using a potentiometer. The Serial Monitor displays
the blink count and delay value.
------------------------------------------------------
*/

int blinkCount = 0;

void setup() {

  pinMode(13, OUTPUT);

  Serial.begin(9600);

}

void loop() {

  int sensorValue = analogRead(A0);

  int delayTime = map(sensorValue,0,1023,100,1000);

  digitalWrite(13,HIGH);
  delay(delayTime);

  digitalWrite(13,LOW);
  delay(delayTime);

  blinkCount++;

  Serial.print("Blink count: ");
  Serial.print(blinkCount);

  Serial.print(" Delay: ");
  Serial.println(delayTime);

}