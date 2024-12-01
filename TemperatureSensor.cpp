#include "TemperatureSensor.h"

//#include <Arduino.h>
#define DHTPIN 5      // DHT11
#define DHTTYPE DHT11 // DHT11

DHT dht(DHTPIN, DHTTYPE);

void initDHT() {
  dht.begin();
  Serial.println("DHT11 initialized");
}

float readTemperature() {
  float temperature = dht.readTemperature();
  if (isnan(temperature)) {
    Serial.println("Failed to read temperature!");
    return -1;
  }
  return temperature;
}

float readHumidity() {
  float humidity = dht.readHumidity();
  if (isnan(humidity)) {
    Serial.println("Failed to read humidity!");
    return -1;
  }
  return humidity;
}
