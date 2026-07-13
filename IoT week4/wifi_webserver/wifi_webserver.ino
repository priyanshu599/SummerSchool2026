/*
-------------------------------------------------------
Project : Wi-Fi Temperature Monitor
Author  : Priyanshu Yadav
-------------------------------------------------------
*/

#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

#define LED_PIN 25

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_PASSWORD";

DHT dht(DHTPIN,DHTTYPE);

WebServer server(80);

bool ledState=false;

String webpage(){

float temp=dht.readTemperature();
float hum=dht.readHumidity();

unsigned long sec=millis()/1000;

String page="";

page+="<!DOCTYPE html>";
page+="<html>";
page+="<head>";

page+="<meta http-equiv='refresh' content='10'>";

page+="<title>ESP32 Weather Station</title>";

page+="</head>";

page+="<body>";

page+="<h1>ESP32 Weather Monitor</h1>";

page+="<h2>Temperature : ";
page+=String(temp);
page+=" °C</h2>";

page+="<h2>Humidity : ";
page+=String(hum);
page+=" %</h2>";

page+="<h2>Uptime : ";
page+=String(sec);
page+=" seconds</h2>";

page+="<form action='/toggle'>";

page+="<button type='submit'>Toggle LED</button>";

page+="</form>";

page+="</body>";

page+="</html>";

return page;

}

void handleRoot(){

server.send(200,"text/html",webpage());

}

void toggleLED(){

ledState=!ledState;

digitalWrite(LED_PIN,ledState);

server.sendHeader("Location","/");

server.send(303);

}

void setup(){

Serial.begin(115200);

dht.begin();

pinMode(LED_PIN,OUTPUT);

WiFi.begin(ssid,password);

Serial.print("Connecting");

while(WiFi.status()!=WL_CONNECTED){

delay(500);

Serial.print(".");

}

Serial.println();

Serial.print("IP Address : ");

Serial.println(WiFi.localIP());

server.on("/",handleRoot);

server.on("/toggle",toggleLED);

server.begin();

}

void loop(){

server.handleClient();

}