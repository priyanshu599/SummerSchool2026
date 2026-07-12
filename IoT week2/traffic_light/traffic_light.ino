/*
-------------------------------------------------------
Project      : Traffic Light Controller
Author       : Priyanshu Yadav
Roll Number  : 24BCA037
Description  :
Traffic light simulation with pedestrian crossing.
-------------------------------------------------------
*/

const int RED = 10;
const int YELLOW = 9;
const int GREEN = 8;
const int BUTTON = 7;

void setup() {

  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);

  pinMode(BUTTON, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {

  // Check Pedestrian Button
  if (digitalRead(BUTTON) == LOW) {

    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, HIGH);

    Serial.print(millis());
    Serial.println(" ms : Pedestrian Crossing (RED)");

    delay(8000);

    return;
  }

  // RED
  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);

  Serial.print(millis());
  Serial.println(" ms : RED");

  delay(5000);

  // YELLOW
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, LOW);

  Serial.print(millis());
  Serial.println(" ms : YELLOW");

  delay(2000);

  // GREEN
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, HIGH);

  Serial.print(millis());
  Serial.println(" ms : GREEN");

  delay(4000);
}