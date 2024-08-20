#include <Arduino.h>
#include <otaserver.h>
#include <kgfx.h>
#include <HTTPClient.h>
#include <ArduinoJSON.h>
#include <Preferences.h>

Preferences preferences;
OTAServer otaserver;
KGFX ui;
HTTPClient http;
JsonDocument json;
String icingaAPIURL;
String icingaAPIUsername;
String icingaAPIPassword;

int refreshTimeInSeconds = 60;
unsigned long lastTime = 0;
bool authFailed = false;
TFT_eSprite textSpr = ui.createSpriteLarge(240, 240);

// CONFIGURATION:
// Please make sure you enabled and configured the new API in your Icinga 2 installation by either setting it up manually
// or use the CLI command for the automatic setup, which also creates a root-user for the API with a random password (icinga2 api setup)
// The default port of the Icinga 2 API is 5665, so the URL to go with would be like: https://myicingaserver.com:5665
// Requires the following API permission(s): status/query
// Read more about Icinga 2 API Setup: https://icinga.com/docs/icinga-2/latest/doc/12-icinga2-api/

void setup() {  
  Serial.begin(460800);
  Serial.println("Starting app");

  otaserver.connectWiFi(); // DO NOT EDIT.
  otaserver.run(); // DO NOT EDIT

  preferences.begin("app", true);
  // icingaAPIURL = "https://hostname:5665";
  // icingaAPIUsername = "username";
  // icingaAPIPassword = "password";
  icingaAPIURL = preferences.getString("icinga_url");
  icingaAPIUsername = preferences.getString("icinga_username");
  icingaAPIPassword = preferences.getString("icinga_password");
  preferences.end();

  ui.init();
  ui.clear();
}

void loop() {
  if((WiFi.status() == WL_CONNECTED)) {
    otaserver.handle(); // DO NOT EDIT

    if (((millis() - lastTime) > refreshTimeInSeconds*1000) || lastTime == (unsigned long)(0)) {
      if (authFailed) {
        return;
      }

      lastTime = millis();
      http.setUserAgent("kublet-icinga");
      http.setAuthorization(icingaAPIUsername.c_str(), icingaAPIPassword.c_str());
      http.begin(icingaAPIURL + "/v1/status/CIB");
      int httpResponseCode = http.GET();

      if (httpResponseCode < 0) {
        ui.drawText(textSpr, "HTTP Error: Probably incorrect or not-reachable Icinga 2 API URL.", Arial_14_Bold, TFT_RED, 0, 0);
        return;
      }

      if (httpResponseCode != HTTP_CODE_OK) {
        ui.drawText(textSpr, "HTTP Error: Probably using wrong API credentials.", Arial_14_Bold, TFT_RED, 0, 0);
        authFailed = true;
        return;
      }

      String payload = http.getString();
      DeserializationError error = deserializeJson(json, payload);
      if (error) {
        ui.drawText(textSpr, "Cannot parse Icinga JSON", Arial_14_Bold, TFT_RED, 0, 0);
        return;
      }

      const String hosts_up = json["results"][0]["status"]["num_hosts_up"];
      const String hosts_down = json["results"][0]["status"]["num_hosts_down"];
      const String services_up = json["results"][0]["status"]["num_services_ok"];
      const String services_down = json["results"][0]["status"]["num_services_critical"];

      ui.drawText(textSpr, "Icinga Status", Arial_14_Bold, TFT_WHITE, 0, 0);

      ui.drawText(textSpr, "Hosts:", Arial_20, TFT_WHITE, 0, 40);
      ui.drawText(textSpr, hosts_up.c_str(), Arial_28_Bold, TFT_GREEN, 0, 80);
      if (json["results"][0]["status"]["num_hosts_down"] > 0) {
        ui.drawText(textSpr, hosts_down.c_str(), Arial_32_Bold, TFT_RED, 140, 75);
      }

      ui.drawText(textSpr, "Services:", Arial_20, TFT_WHITE, 0, 140);
      ui.drawText(textSpr, services_up.c_str(), Arial_28_Bold, TFT_GREEN, 0, 180);
      if (json["results"][0]["status"]["num_services_critical"] > 0) {
        ui.drawText(textSpr, services_down.c_str(), Arial_32_Bold, TFT_RED, 140, 175);
      }

      http.end();
    }
  }

  delay(1);
}
