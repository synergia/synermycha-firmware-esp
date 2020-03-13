#include "wifi.h"

WIFI::WIFI(){}


void WIFI::setup() {
    wifiManager.setConnectTimeout(5);
    wifiManager.setConfigPortalTimeout(20);
    wifiManager.setAPCallback(this->configModeCallback);
    wifiManager.autoConnect(SSID);
}

boolean WIFI::isConnected() {
    if (WiFi.status() == WL_CONNECTED) {
        return true;
    } else {
        return false;
    }
}


void WIFI::configModeCallback (WiFiManager *wifi_manager) {
  Serial.println(WiFi.softAPIP());
  Serial.println(wifi_manager->getConfigPortalSSID());
}