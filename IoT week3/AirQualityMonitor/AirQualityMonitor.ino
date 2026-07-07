#include <DHT.h>

#define MQ135 34

#define DHTPIN 4

#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

void setup() {

  Serial.begin(115200);

  dht.begin();

}

void loop() {

  int air = analogRead(MQ135);

  float temp = dht.readTemperature();

  float hum = dht.readHumidity();

  Serial.print("Air Quality : ");

  Serial.println(air);

  Serial.print("Temperature : ");

  Serial.print(temp);

  Serial.println(" C");

  Serial.print("Humidity : ");

  Serial.print(hum);

  Serial.println(" %");

  if(air>2500){

    Serial.println("Poor Air Quality");

  }

  else{

    Serial.println("Air Quality Normal");

  }

  Serial.println("----------------------------");

  delay(2000);

}