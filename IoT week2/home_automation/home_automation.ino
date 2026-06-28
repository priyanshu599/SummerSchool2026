
const int ldrPin = A0;
const int tempPin = A1;

const int pirPin = 2;
const int buttonPin = 3;

const int buzzer = 4;

const int led1 = 6;   
const int led2 = 8;  

bool buttonState = false;
bool lastButton = HIGH;

void setup() {

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(pirPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {


  int ldr = analogRead(ldrPin);

  Serial.print("LDR = ");
  Serial.println(ldr);

  if (ldr < 500)
    digitalWrite(led1, HIGH);
  else
    digitalWrite(led1, LOW);


  int value = analogRead(tempPin);

  float voltage = value * 5.0 / 1023.0;

  float temp = (voltage - 0.5) * 100;

  Serial.print("Temp = ");
  Serial.println(temp);

  if (temp > 35) {

    tone(buzzer, 1000);

  } else {

    noTone(buzzer);

  }


  if (digitalRead(pirPin)) {

    digitalWrite(led2, HIGH);

  } else {

    digitalWrite(led2, LOW);

  }


  bool current = digitalRead(buttonPin);

  if (lastButton == HIGH && current == LOW) {

    buttonState = !buttonState;

    digitalWrite(led1, buttonState);

    delay(200);

  }

  lastButton = current;

}