int ledPins[] = {
  0, 1, 2, 3, 4, 5, 6,
  7, 8, 9, 10, 11, 12, 13,
  A4, A5
};

void setup() {

  for(int i = 0; i < 16; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  pinMode(A0, INPUT);
}

void loop() {

  int potValue = analogRead(A0);

  int ledsOn = map(potValue, 0, 1023, 0, 16);

  for(int i = 0; i < 16; i++) {

    if(i < ledsOn)
      digitalWrite(ledPins[i], HIGH);
    else
      digitalWrite(ledPins[i], LOW);
  }

  delay(50);
}