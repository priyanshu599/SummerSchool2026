/*
-------------------------------------------------------
Project      : Digital Piano
Author       : Priyanshu Yadav
Roll Number  : 24BCA037
Description  :
4-key digital piano with Major/Minor mode and
two-key chord substitute.
-------------------------------------------------------
*/

const int buzzer = 8;

const int btnDo = 2;
const int btnRe = 3;
const int btnMi = 4;
const int btnFa = 5;
const int modeBtn = 6;

bool majorMode = true;
bool lastModeState = HIGH;

void setup() {

  pinMode(btnDo, INPUT_PULLUP);
  pinMode(btnRe, INPUT_PULLUP);
  pinMode(btnMi, INPUT_PULLUP);
  pinMode(btnFa, INPUT_PULLUP);
  pinMode(modeBtn, INPUT_PULLUP);

  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);

}

void loop() {

  bool modeState = digitalRead(modeBtn);

  if (lastModeState == HIGH && modeState == LOW) {

    majorMode = !majorMode;

    Serial.print("Mode : ");

    if (majorMode)
      Serial.println("Major");
    else
      Serial.println("Minor");

    delay(250);

  }

  lastModeState = modeState;

  int pressed = 0;

  if (!digitalRead(btnDo)) pressed++;
  if (!digitalRead(btnRe)) pressed++;
  if (!digitalRead(btnMi)) pressed++;
  if (!digitalRead(btnFa)) pressed++;

  if (pressed >= 2) {

    tone(buzzer,392);     // Sol

  }

  else if (!digitalRead(btnDo)) {

    tone(buzzer, majorMode ? 262 : 247);

  }

  else if (!digitalRead(btnRe)) {

    tone(buzzer, majorMode ? 294 : 277);

  }

  else if (!digitalRead(btnMi)) {

    tone(buzzer, majorMode ? 330 : 311);

  }

  else if (!digitalRead(btnFa)) {

    tone(buzzer, majorMode ? 349 : 330);

  }

  else {

    noTone(buzzer);

  }

}