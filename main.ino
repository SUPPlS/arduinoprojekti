#include <Arduino.h>
#include "WiFiComponent.h"
#include "PhilipsHue.h"
#include "TemperatureSensor.h"
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

//WiFi
const char* ssid = 
const char* password = 

//Philips Hue Bridge
const char* bridge_ip = 
const char* username = 

PhilipsHue hue(bridge_ip, username);

void setup() {
Serial.begin(115200); // Serial monitor for debugging
  
// Initialize WiFi
initWiFi(ssid, password);

// Initialize DHT sensor
initDHT();
}

void loop() {
  if (espSerial.available()) {
  Serial.write(espSerial.read());
  }
  
// if (Serial.available()) {
// espSerial.write(Serial.read());
// }

  // Read temperature and humidity
  float temperature = readTemperature();
  float humidity = readHumidity();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C ");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");


  // Turn on light 1
    hue.turnOn("");
    delay(5000);

  // Set brightness of light 1 to 128
    hue.setBrightness("", 128);
    delay(5000);

  // Turn off light 1
    hue.turnOff("");
    delay(5000);

  delay(10000); // Delay between readings
}
