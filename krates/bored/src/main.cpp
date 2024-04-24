#include <Arduino.h>
#include <otaserver.h>
#include <kgfx.h>
#include <HTTPClient.h>
#include <ArduinoJSON.h>
#include <TFT_eSPI.h>

OTAServer otaserver;
KGFX ui;
Preferences preferences;
JsonDocument doc;

const char *endpoint = "https://www.boredapi.com/api/activity";
unsigned long lastTime = 0;
unsigned long timerDelay = 600000;

TFT_eSprite textSpr = ui.createSprite(240, 150);

void setup() {
  Serial.begin(460800);
  Serial.println("Starting app");

  otaserver.connectWiFi(); // DO NOT EDIT.
  otaserver.run(); // DO NOT EDIT

  ui.init();
  ui.clear();
}

void loop() {
  if((WiFi.status() == WL_CONNECTED)) {
    otaserver.handle(); // DO NOT EDIT

    if (((millis() - lastTime) > timerDelay) || lastTime == (unsigned long)(0)) {
      HTTPClient http;
      http.begin(endpoint);
      int httpResponseCode = http.GET();
        
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
        deserializeJson(doc, payload);
        const char* activity = doc["activity"];
        ui.drawText(textSpr, activity, Arial_24, TFT_YELLOW, 0, 0);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
      
      lastTime = millis();
    }
    
  }

  delay(1);
}
