#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <DHT.h>
#include "config.h"

// ---------- DHT11 ----------
#define DHTPIN 15
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// Function declaration
void fetchWeather();

void setup() {
  Serial.begin(115200);

  dht.begin();

  delay(3000);

  // Connect to WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {

  fetchWeather();

  Serial.println("\nWaiting 30 seconds...\n");

  delay(30000);
}

void fetchWeather() {

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi Disconnected!");
    return;
  }

  String url = "http://api.openweathermap.org/data/2.5/weather?q=" +
               String(CITY) + "," +
               String(COUNTRY_CODE) +
               "&appid=" + String(API_KEY) +
               "&units=metric";

  HTTPClient http;

  http.begin(url);

  int httpCode = http.GET();

  if (httpCode == HTTP_CODE_OK) {

    String payload = http.getString();

    DynamicJsonDocument doc(2048);

    DeserializationError error = deserializeJson(doc, payload);

    if (error) {
      Serial.println("JSON Parsing Failed!");
      http.end();
      return;
    }

    // API Values
    String city = doc["name"];
    float apiTemp = doc["main"]["temp"];
    int apiHumidity = doc["main"]["humidity"];
    String description = doc["weather"][0]["description"];

    // Local DHT11 Values
    float localTemp = dht.readTemperature();
    float localHumidity = dht.readHumidity();

    if (isnan(localTemp) || isnan(localHumidity)) {
      Serial.println("Failed to read DHT11!");
      http.end();
      return;
    }

    float tempDifference = localTemp - apiTemp;

    Serial.println("--------------------------------------");
    Serial.println("      WEATHER COMPARISON");
    Serial.println("--------------------------------------");

    Serial.print("City                : ");
    Serial.println(city);

    Serial.print("Weather             : ");
    Serial.println(description);

    Serial.print("API Temperature     : ");
    Serial.print(apiTemp);
    Serial.println(" °C");

    Serial.print("DHT11 Temperature   : ");
    Serial.print(localTemp);
    Serial.println(" °C");

    Serial.print("Temperature Difference : ");
    Serial.print(tempDifference);
    Serial.println(" °C");

    Serial.print("API Humidity        : ");
    Serial.print(apiHumidity);
    Serial.println(" %");

    Serial.print("DHT11 Humidity      : ");
    Serial.print(localHumidity);
    Serial.println(" %");

    Serial.println("--------------------------------------");
  }

  else {

    Serial.print("HTTP Error Code: ");
    Serial.println(httpCode);

    String response = http.getString();
    Serial.println(response);
  }

  http.end();
}