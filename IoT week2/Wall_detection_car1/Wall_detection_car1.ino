const int ledPin = 2;
const int buzzer = 3;

const int IN1 = 4;
const int ENA = 5;
const int IN2 = 6;
const int IN3 = 7;
const int IN4 = 8;
const int trigPin = 9;
const int echoPin = 10;
const int ENB = 11;

long duration;
int distance;

void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);

}

void loop() {

  // Measure Distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 30) {

    digitalWrite(ledPin, LOW);
    noTone(buzzer);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    analogWrite(ENA, 255);
    analogWrite(ENB, 255);

  }


  else if (distance > 15) {

    digitalWrite(ledPin, LOW);
    noTone(buzzer);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    analogWrite(ENA, 120);
    analogWrite(ENB, 120);

  }

  else {

    analogWrite(ENA, 0);
    analogWrite(ENB, 0);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);

    digitalWrite(ledPin, HIGH);

    tone(buzzer, 1000);

  }

  delay(100);

}