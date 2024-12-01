#ifndef WIFICOMPONENT_H
#define WIFICOMPONENT_H

#include <SoftwareSerial.h>

extern SoftwareSerial espSerial;

void initWiFi(const char* ssid, const char* password);
bool sendCommand(String command, const int timeout, String expectedResponse);

#endif // WIFICOMPONENT_H
