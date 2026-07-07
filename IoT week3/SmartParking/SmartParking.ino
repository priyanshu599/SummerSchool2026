/*
--------------------------------------
Smart Parking
ESP32
--------------------------------------
*/

#define TRIG 5
#define ECHO 18

long duration;

float distance;

void setup() {

  Serial.begin(115200);

  pinMode(TRIG, OUTPUT);

  pinMode(ECHO, INPUT);

}

void loop() {

  digitalWrite(TRIG, LOW);

  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);

  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance : ");

  Serial.print(distance);

  Serial.println(" cm");

  if(distance < 10){

    Serial.println("Parking Slot Occupied");

  }

  else{

    Serial.println("Parking Slot Available");

  }

  delay(1000);

}