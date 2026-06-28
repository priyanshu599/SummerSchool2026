const int tempPin = A0;

const int greenLED = 2;
const int redLED = 3;
const int buzzer = 4;

float temperature;

void setup() {

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);

}

void loop() {

  int sensorValue = analogRead(tempPin);

  float voltage = sensorValue * (5.0 / 1023.0);

  temperature = (voltage - 0.5) * 100;

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  if (temperature < 35) {

    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    noTone(buzzer);

  }

  else if (temperature < 45) {

    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);

    tone(buzzer, 800);
    delay(200);
    noTone(buzzer);

  }

  else {

    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);

    tone(buzzer, 1200);

  }

  delay(500);

}