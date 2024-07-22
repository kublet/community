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

  ui.tft.setTTFFont(Arial_24_Bold);
  ui.tft.setTextColor(TFT_BLUE, TFT_BLACK);
  const char *helloTxt = "Hello";
  int w = ui.tft.TTFtextWidth(helloTxt);
  ui.tft.setCursor((240-w)/2,20);
  ui.tft.print(helloTxt);

  ui.tft.setTTFFont(Arial_24_Bold);
  ui.tft.setTextColor(TFT_BLUE, TFT_BLACK);
  const char *txt = "Your text here";
  int w2 = ui.tft.TTFtextWidth(txt);
  ui.tft.setCursor((240-w2)/2,100);
  ui.tft.print(txt);
}

void loop() {
  if((WiFi.status() == WL_CONNECTED)) {
    otaserver.handle(); // DO NOT EDIT
  }

  delay(1);
}
