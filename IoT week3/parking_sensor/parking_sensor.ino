/*
-------------------------------------------------------
Project      : Ultrasonic Parking Sensor
Author       : Priyanshu Yadav
Roll Number  : 24BCA037

Description:
Parking distance alert using HC-SR04.
Uses millis() for non-blocking timing.
-------------------------------------------------------
*/

const int trigPin = 9;
const int echoPin = 10;

const int greenLED = 4;
const int yellowLED = 5;
const int redLED = 6;
const int buzzer = 8;

unsigned long previousMillis = 0;
bool outputState = false;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  float distance = (duration * 0.034) / 2;

  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.print(" cm  ");

  unsigned long currentMillis = millis();

  // SAFE ZONE
  if (distance > 50) {

    Serial.println("SAFE");

    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);

    digitalWrite(buzzer, LOW);

  }

  // WARNING ZONE
  else if (distance > 20) {

    Serial.println("WARNING");

    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);

    if (currentMillis - previousMillis >= 500) {

      previousMillis = currentMillis;

      outputState = !outputState;

      digitalWrite(buzzer, outputState);
    }

  }

  // DANGER ZONE
  else if (distance > 10) {

    Serial.println("DANGER");

    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);

    if (currentMillis - previousMillis >= 200) {

      previousMillis = currentMillis;

      outputState = !outputState;

      digitalWrite(buzzer, outputState);
    }

  }

  // EMERGENCY ZONE
  else {

    Serial.println("STOP");

    digitalWrite(buzzer, HIGH);

    if (currentMillis - previousMillis >= 100) {

      previousMillis = currentMillis;

      outputState = !outputState;

      digitalWrite(greenLED, outputState);
      digitalWrite(yellowLED, outputState);
      digitalWrite(redLED, outputState);

    }

  }
}