#include "PhilipsHue.h"

PhilipsHue::PhilipsHue(const char* bridge_ip, const char* username) {
    this->bridge_ip = String(bridge_ip);
    this->username = String(username);
}

void PhilipsHue::turnOn(const String& light_id) {
    String url = "http://" + bridge_ip + "/clip/v2/resource/light/" + light_id;
    StaticJsonDocument<200> doc;
    doc["on"] = true;
    String payload;
    serializeJson(doc, payload);
    sendRequest(url, payload);
}

void PhilipsHue::turnOff(const String& light_id) {
    String url = "http://" + bridge_ip + "/clip/v2/resource/light/" + light_id;
    StaticJsonDocument<200> doc;
    doc["on"] = false;
    String payload;
    serializeJson(doc, payload);
    sendRequest(url, payload);
}

void PhilipsHue::setBrightness(const String& light_id, int brightness) {
    String url = "http://" + bridge_ip + "/clip/v2/resource/light/" + light_id;
    StaticJsonDocument<200> doc;
    doc["bri"] = brightness;
    String payload;
    serializeJson(doc, payload);
    sendRequest(url, payload);
}

void PhilipsHue::sendRequest(const String& url, const String& payload) {
    if (WiFi.status() == WL_CONNECTED) {
        WiFiClient client;
        HTTPClient http;
        http.begin(client, url);
        http.addHeader("Content-Type", "application/json");
        int httpResponseCode = http.PUT(payload);
        if (httpResponseCode > 0) {
            String response = http.getString();
            Serial.println(httpResponseCode);
            Serial.println(response);
        } else {
            Serial.print("Error on sending PUT: ");
            Serial.println(httpResponseCode);
        }
        http.end();
    } else {
        Serial.println("WiFi not connected");
    }
}





