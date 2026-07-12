/*
-------------------------------------------------------
Project      : PWM Fading Night Light
Author       : Priyanshu Yadav
Roll Number  : 24BCA037
Description  :
Automatic night light with three lighting modes.
-------------------------------------------------------
*/

const int led = 9;
const int button = 2;

int mode = 1;
bool lastButtonState = HIGH;

void setup() {

  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  Serial.begin(9600);

  Serial.println("Mode 1 : Slow Breathing");

}

void loop() {

  bool buttonState = digitalRead(button);

  if (lastButtonState == HIGH && buttonState == LOW) {

    mode++;

    if (mode > 3)
      mode = 1;

    Serial.print("Current Mode : ");

    if (mode == 1)
      Serial.println("Slow Breathing");

    if (mode == 2)
      Serial.println("Fast Pulse");

    if (mode == 3)
      Serial.println("SOS Pattern");

    delay(250);

  }

  lastButtonState = buttonState;

  if (mode == 1)
    slowBreathing();

  else if (mode == 2)
    fastPulse();

  else
    sosPattern();

}

void slowBreathing() {

  for (int i = 0; i <= 255; i++) {

    analogWrite(led, i);
    delay(6);

  }

  for (int i = 255; i >= 0; i--) {

    analogWrite(led, i);
    delay(6);

  }

}

void fastPulse() {

  for (int i = 0; i <= 255; i += 10) {

    analogWrite(led, i);
    delay(10);

  }

  for (int i = 255; i >= 0; i -= 10) {

    analogWrite(led, i);
    delay(10);

  }

}

void dot() {

  analogWrite(led,255);
  delay(200);

  analogWrite(led,0);
  delay(200);

}

void dash() {

  analogWrite(led,255);
  delay(600);

  analogWrite(led,0);
  delay(200);

}

void sosPattern() {

  dot();
  dot();
  dot();

  dash();
  dash();
  dash();

  dot();
  dot();
  dot();

  delay(1000);

}