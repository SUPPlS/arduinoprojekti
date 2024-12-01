//#include <Arduino.h>
#include "WiFiComponent.h"

SoftwareSerial espSerial(2, 3); // RX, TX

bool sendCommand(String command, const int timeout, String expectedResponse) {
  String response = "";
  espSerial.println(command);
  long int time = millis();
  while ((millis() - time) < timeout) {
    while (espSerial.available()) {
      char c = espSerial.read();
      response += c;
    }
    if (response.indexOf(expectedResponse) != -1) {
      Serial.println(response);
      return true;
    }
  }
  Serial.println(response);
  return false;
}

void initWiFi(const char* ssid, const char* password) {
  espSerial.begin(115200);
  Serial.println("Starting ESP8266");
  delay(2000); // Odotellaan käynnistymistä

  if (sendCommand("AT", 5000, "OK")) {
    if (sendCommand("AT+CWMODE=1", 5000, "OK")) { 
      if (sendCommand("AT+CWJAP=\"" + String(ssid) + "\",\"" + String(password) + "\"", 15000, "OK")) { // Connect to WiFi
        Serial.println("ESP8266 setup complete");
      } else {
        Serial.println("Error: AT+CWJAP failed");
      }
    } else {
      Serial.println("Error: AT+CWMODE=1 failed");
    }
  } else {
    Serial.println("Error: AT failed");
  }
}
