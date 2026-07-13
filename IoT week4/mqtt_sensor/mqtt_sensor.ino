/*
-------------------------------------------------------
Project : MQTT Sensor Publisher
Author  : Priyanshu Yadav
-------------------------------------------------------
*/

#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

#define LED_PIN 25

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

const char* broker = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

DHT dht(DHTPIN,DHTTYPE);

void callback(char* topic, byte* payload, unsigned int length){

  String msg="";

  for(int i=0;i<length;i++)
    msg+=(char)payload[i];

  Serial.print("Received : ");
  Serial.println(msg);

  if(msg=="ON")
    digitalWrite(LED_PIN,HIGH);

  else if(msg=="OFF")
    digitalWrite(LED_PIN,LOW);

}

void reconnect(){

  while(!client.connected()){

    Serial.println("Connecting MQTT...");

    if(client.connect("ESP32Client")){

      Serial.println("Connected");

      client.subscribe("iitjammu/summer26/priyanshu/led_control");

    }

    else{

      delay(2000);

    }

  }

}

void setup(){

  Serial.begin(115200);

  pinMode(LED_PIN,OUTPUT);

  dht.begin();

  WiFi.begin(ssid,password);

  while(WiFi.status()!=WL_CONNECTED){

    delay(500);

    Serial.print(".");

  }

  client.setServer(broker,1883);

  client.setCallback(callback);

}

void loop(){

  if(!client.connected())
    reconnect();

  client.loop();

  static unsigned long last=0;

  if(millis()-last>5000){

    last=millis();

    float temp=dht.readTemperature();
    float hum=dht.readHumidity();

    StaticJsonDocument<128> doc;

    doc["value"]=temp;
    doc["unit"]="C";
    doc["ts"]=millis();

    char buffer[128];

    serializeJson(doc,buffer);

    client.publish("iitjammu/summer26/priyanshu/temperature",buffer);

    doc.clear();

    doc["value"]=hum;
    doc["unit"]="%";
    doc["ts"]=millis();

    serializeJson(doc,buffer);

    client.publish("iitjammu/summer26/priyanshu/humidity",buffer);

    Serial.println("Published");

  }

}