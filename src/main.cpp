#include "wifi.h"

#include <WiFiManager.h>
#include <PubSubClient.h>

WIFI wifi;

void setup() {
  Serial.begin(9600);
  wifi.setup();

}

void loop() {

}