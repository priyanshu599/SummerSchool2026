/*
-------------------------------------------------------
Project      : BLE Sensor Dashboard
Author       : Priyanshu Yadav
Roll Number  : 24BCA037
-------------------------------------------------------
*/

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN,DHTTYPE);

BLECharacteristic *tempChar;
BLECharacteristic *humChar;
BLECharacteristic *timeChar;

#define SERVICE_UUID        "12345678-1234-1234-1234-1234567890AB"
#define TEMP_UUID           "11111111-1234-1234-1234-1234567890AB"
#define HUM_UUID            "22222222-1234-1234-1234-1234567890AB"
#define TIME_UUID           "33333333-1234-1234-1234-1234567890AB"

void setup() {

  Serial.begin(115200);

  dht.begin();

  BLEDevice::init("ESP32 Weather Station");

  BLEServer *server = BLEDevice::createServer();

  BLEService *service = server->createService(SERVICE_UUID);

  tempChar = service->createCharacteristic(
      TEMP_UUID,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_NOTIFY
  );

  humChar = service->createCharacteristic(
      HUM_UUID,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_NOTIFY
  );

  timeChar = service->createCharacteristic(
      TIME_UUID,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_NOTIFY
  );

  tempChar->addDescriptor(new BLE2902());
  humChar->addDescriptor(new BLE2902());
  timeChar->addDescriptor(new BLE2902());

  service->start();

  BLEAdvertising *advertising = BLEDevice::getAdvertising();

  advertising->start();

  Serial.println("BLE Started");

}

void loop() {

  float temp = dht.readTemperature();

  float hum = dht.readHumidity();

  unsigned long t = millis();

  tempChar->setValue(String(temp).c_str());
  humChar->setValue(String(hum).c_str());
  timeChar->setValue(String(t).c_str());

  tempChar->notify();
  humChar->notify();
  timeChar->notify();

  Serial.print("Temperature : ");
  Serial.println(temp);

  Serial.print("Humidity : ");
  Serial.println(hum);

  Serial.print("Timestamp : ");
  Serial.println(t);

  Serial.println("---------------------");

  delay(3000);

}/*
-------------------------------------------------------
Project      : BLE Sensor Dashboard
Author       : Priyanshu Yadav
Roll Number  : 24BCA037
-------------------------------------------------------
*/

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN,DHTTYPE);

BLECharacteristic *tempChar;
BLECharacteristic *humChar;
BLECharacteristic *timeChar;

#define SERVICE_UUID        "12345678-1234-1234-1234-1234567890AB"
#define TEMP_UUID           "11111111-1234-1234-1234-1234567890AB"
#define HUM_UUID            "22222222-1234-1234-1234-1234567890AB"
#define TIME_UUID           "33333333-1234-1234-1234-1234567890AB"

void setup() {

  Serial.begin(115200);

  dht.begin();

  BLEDevice::init("ESP32 Weather Station");

  BLEServer *server = BLEDevice::createServer();

  BLEService *service = server->createService(SERVICE_UUID);

  tempChar = service->createCharacteristic(
      TEMP_UUID,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_NOTIFY
  );

  humChar = service->createCharacteristic(
      HUM_UUID,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_NOTIFY
  );

  timeChar = service->createCharacteristic(
      TIME_UUID,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_NOTIFY
  );

  tempChar->addDescriptor(new BLE2902());
  humChar->addDescriptor(new BLE2902());
  timeChar->addDescriptor(new BLE2902());

  service->start();

  BLEAdvertising *advertising = BLEDevice::getAdvertising();

  advertising->start();

  Serial.println("BLE Started");

}

void loop() {

  float temp = dht.readTemperature();

  float hum = dht.readHumidity();

  unsigned long t = millis();

  tempChar->setValue(String(temp).c_str());
  humChar->setValue(String(hum).c_str());
  timeChar->setValue(String(t).c_str());

  tempChar->notify();
  humChar->notify();
  timeChar->notify();

  Serial.print("Temperature : ");
  Serial.println(temp);

  Serial.print("Humidity : ");
  Serial.println(hum);

  Serial.print("Timestamp : ");
  Serial.println(t);

  Serial.println("---------------------");

  delay(3000);

}/*
-------------------------------------------------------
Project      : BLE Sensor Dashboard
Author       : Priyanshu Yadav
Roll Number  : 24BCA037
-------------------------------------------------------
*/

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN,DHTTYPE);

BLECharacteristic *tempChar;
BLECharacteristic *humChar;
BLECharacteristic *timeChar;

#define SERVICE_UUID        "12345678-1234-1234-1234-1234567890AB"
#define TEMP_UUID           "11111111-1234-1234-1234-1234567890AB"
#define HUM_UUID            "22222222-1234-1234-1234-1234567890AB"
#define TIME_UUID           "33333333-1234-1234-1234-1234567890AB"

void setup() {

  Serial.begin(115200);

  dht.begin();

  BLEDevice::init("ESP32 Weather Station");

  BLEServer *server = BLEDevice::createServer();

  BLEService *service = server->createService(SERVICE_UUID);

  tempChar = service->createCharacteristic(
      TEMP_UUID,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_NOTIFY
  );

  humChar = service->createCharacteristic(
      HUM_UUID,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_NOTIFY
  );

  timeChar = service->createCharacteristic(
      TIME_UUID,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_NOTIFY
  );

  tempChar->addDescriptor(new BLE2902());
  humChar->addDescriptor(new BLE2902());
  timeChar->addDescriptor(new BLE2902());

  service->start();

  BLEAdvertising *advertising = BLEDevice::getAdvertising();

  advertising->start();

  Serial.println("BLE Started");

}

void loop() {

  float temp = dht.readTemperature();

  float hum = dht.readHumidity();

  unsigned long t = millis();

  tempChar->setValue(String(temp).c_str());
  humChar->setValue(String(hum).c_str());
  timeChar->setValue(String(t).c_str());

  tempChar->notify();
  humChar->notify();
  timeChar->notify();

  Serial.print("Temperature : ");
  Serial.println(temp);

  Serial.print("Humidity : ");
  Serial.println(hum);

  Serial.print("Timestamp : ");
  Serial.println(t);

  Serial.println("---------------------");

  delay(3000);

}/*
-------------------------------------------------------
Project      : BLE Sensor Dashboard
Author       : Priyanshu Yadav
Roll Number  : 24BCA037
-------------------------------------------------------
*/

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN,DHTTYPE);

BLECharacteristic *tempChar;
BLECharacteristic *humChar;
BLECharacteristic *timeChar;

#define SERVICE_UUID        "12345678-1234-1234-1234-1234567890AB"
#define TEMP_UUID           "11111111-1234-1234-1234-1234567890AB"
#define HUM_UUID            "22222222-1234-1234-1234-1234567890AB"
#define TIME_UUID           "33333333-1234-1234-1234-1234567890AB"

void setup() {

  Serial.begin(115200);

  dht.begin();

  BLEDevice::init("ESP32 Weather Station");

  BLEServer *server = BLEDevice::createServer();

  BLEService *service = server->createService(SERVICE_UUID);

  tempChar = service->createCharacteristic(
      TEMP_UUID,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_NOTIFY
  );

  humChar = service->createCharacteristic(
      HUM_UUID,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_NOTIFY
  );

  timeChar = service->createCharacteristic(
      TIME_UUID,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_NOTIFY
  );

  tempChar->addDescriptor(new BLE2902());
  humChar->addDescriptor(new BLE2902());
  timeChar->addDescriptor(new BLE2902());

  service->start();

  BLEAdvertising *advertising = BLEDevice::getAdvertising();

  advertising->start();

  Serial.println("BLE Started");

}

void loop() {

  float temp = dht.readTemperature();

  float hum = dht.readHumidity();

  unsigned long t = millis();

  tempChar->setValue(String(temp).c_str());
  humChar->setValue(String(hum).c_str());
  timeChar->setValue(String(t).c_str());

  tempChar->notify();
  humChar->notify();
  timeChar->notify();

  Serial.print("Temperature : ");
  Serial.println(temp);

  Serial.print("Humidity : ");
  Serial.println(hum);

  Serial.print("Timestamp : ");
  Serial.println(t);

  Serial.println("---------------------");

  delay(3000);

}