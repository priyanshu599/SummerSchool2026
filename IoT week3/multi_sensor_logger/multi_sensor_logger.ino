/*
-------------------------------------------------------
Project      : Multi Sensor Data Logger
Author       : Priyanshu Yadav
Roll Number  : 24BCA037

Reads:
• DHT22
• LDR
• HC-SR04

Logs data every 5 seconds.
-------------------------------------------------------
*/

#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

#define LDR_PIN A0

#define TRIG_PIN 9
#define ECHO_PIN 10

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(9600);

  dht.begin();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

}

void loop() {

  // ---------------- DHT ----------------

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  // ---------------- LDR ----------------

  int rawLight = analogRead(LDR_PIN);

  int lightPercent = map(rawLight,0,1023,0,100);

  String status;

  if(lightPercent>=70)
    status="Bright";

  else if(lightPercent>=40)
    status="Normal";

  else
    status="Dark";

  // ---------------- Ultrasonic ----------------

  digitalWrite(TRIG_PIN,LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN,HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN,LOW);

  long duration=pulseIn(ECHO_PIN,HIGH);

  float distance=(duration*0.034)/2;

  // ---------------- Output ----------------

  Serial.println("========================");

  Serial.print("Time      : ");
  Serial.print(millis());
  Serial.println(" ms");

  Serial.print("Temp      : ");
  Serial.print(temp);
  Serial.print(" C");

  Serial.print(" | Humidity: ");
  Serial.print(hum);
  Serial.println("%");

  Serial.print("Light     : ");
  Serial.print(lightPercent);
  Serial.print("% (");
  Serial.print(status);
  Serial.println(")");

  Serial.print("Distance  : ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.println("========================");

  delay(5000);

}