#include "wifi.h"
#include "mqtt_client.h"

WIFI wifi;
MQTTClient mqtt_client;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); 
  Serial.begin(9600);
  wifi.setup();
  mqtt_client.setup();
}


void loop() {
  mqtt_client.assureConnection();
  mqtt_client.loop();

  // unsigned long now = millis();
  // if (now - lastMsg > 2000) {
  //   lastMsg = now;
  //   ++value;
  //   snprintf (msg, MSG_BUFFER_SIZE, "hello world #%ld", value);
  //   Serial.print("Publish message: ");
  //   Serial.println(msg);
  //   client.publish("outTopic", msg);
  // }

}