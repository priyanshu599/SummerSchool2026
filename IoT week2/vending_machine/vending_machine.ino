/*
-------------------------------------------------------
Project      : Vending Machine State Machine
Author       : Priyanshu Yadav
Roll Number  : 24BCA037

State Transition Diagram

        +-------+
        | IDLE  |
        +-------+
             |
      Insert Coin
             |
             v
 +-------------------+
 | COIN_INSERTED     |
 +-------------------+
      |         |
 Cancel |     Select Item
      |         |
      v         v
    IDLE   +----------------+
           | ITEM_SELECTED  |
           +----------------+
                   |
              Dispensing
                   |
                   v
           +---------------+
           | DISPENSING    |
           +---------------+
                   |
                Complete
                   |
                   v
                 IDLE
-------------------------------------------------------
*/
enum State {
  IDLE,
  COIN_INSERTED,
  ITEM_SELECTED,
  DISPENSING
};

State currentState = IDLE;

const int coinBtn = 2;
const int selectBtn = 3;
const int cancelBtn = 4;

const int redLED = 8;
const int yellowLED = 9;
const int greenLED = 10;

void setup() {

  pinMode(coinBtn, INPUT_PULLUP);
  pinMode(selectBtn, INPUT_PULLUP);
  pinMode(cancelBtn, INPUT_PULLUP);

  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  Serial.begin(9600);

  Serial.println("State : IDLE");
}

void loop() {

  switch(currentState) {

    case IDLE:

      digitalWrite(redLED, HIGH);
      digitalWrite(yellowLED, LOW);
      digitalWrite(greenLED, LOW);

      if(digitalRead(coinBtn) == LOW){

        currentState = COIN_INSERTED;

        Serial.println("Transition : IDLE -> COIN_INSERTED");

        delay(300);

      }

    break;

    case COIN_INSERTED:

      digitalWrite(redLED, LOW);
      digitalWrite(yellowLED, HIGH);
      digitalWrite(greenLED, LOW);

      if(digitalRead(selectBtn)==LOW){

        currentState = ITEM_SELECTED;

        Serial.println("Transition : COIN_INSERTED -> ITEM_SELECTED");

        delay(300);

      }

      if(digitalRead(cancelBtn)==LOW){

        currentState = IDLE;

        Serial.println("Transition : COIN_INSERTED -> IDLE");

        delay(300);

      }

    break;

    case ITEM_SELECTED:

      digitalWrite(redLED, LOW);
      digitalWrite(yellowLED, LOW);
      digitalWrite(greenLED, HIGH);

      Serial.println("Transition : ITEM_SELECTED -> DISPENSING");

      delay(1000);

      currentState = DISPENSING;

    break;

    case DISPENSING:

      Serial.println("Dispensing Item...");

      delay(3000);

      Serial.println("Transition : DISPENSING -> IDLE");

      currentState = IDLE;

    break;

  }

}