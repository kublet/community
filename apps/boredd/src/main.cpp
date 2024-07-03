
#include <Arduino.h>
#include <otaserver.h>
#include <kgfx.h>

OTAServer otaserver;
KGFX ui;

void setup() {
  Serial.begin(460800);
  Serial.println("Starting app");

  otaserver.connectWiFi(); // DO NOT EDIT.
  otaserver.run(); // DO NOT EDIT

  ui.init();
  ui.clear();
  ui.drawText("hello", Arial_28, TFT_YELLOW, 0, 0);
  ui.tft().drawCircle(50, 50, 10, TFT_YELLOW);
}

void loop() {
  if((WiFi.status() == WL_CONNECTED)) {
    otaserver.handle(); // DO NOT EDIT
  }

  delay(1);
}
