#ifndef PHILIPSHUE_H
#define PHILIPSHUE_H

#include <Arduino.h>
#include <ESP8266WiFi.h>  
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

class PhilipsHue {
public:
    PhilipsHue(const char* bridge_ip, const char* username);
    void turnOn(const String& light_id);
    void turnOff(const String& light_id);
    void setBrightness(const String& light_id, int brightness);

private:
    String bridge_ip;
    String username;
    void sendRequest(const String& url, const String& payload);
};

#endif
