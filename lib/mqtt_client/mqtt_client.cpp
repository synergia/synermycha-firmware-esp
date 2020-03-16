#include "mqtt_client.h"

MQTTClient::MQTTClient() : PubSubClient(this->wifi_client){

    // const char* mqtt_server = MQTT_SERVER_IP;
    // unsigned long lastMsg = 0;
    // char msg[MSG_BUFFER_SIZE];
    // int value = 0;
}

void MQTTClient::setup() {
    setServer(MQTT_SERVER_IP, MQTT_SERVER_PORT);
    setCallback(this->callback);
}



void MQTTClient::callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1') {
    digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is active low on the ESP-01)
  } else {
    digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  }

}

void MQTTClient::assureConnection() {
    if (!connected()) reconnect();
}

void MQTTClient::reconnect() {
    
  // Loop until we're reconnected
  while (!connected()) {
    Serial.print("Attempting MQTT connection...");

    if (connect(MQTT_CLIENT_ID)) {
      Serial.println("connected");
      // Once connecttry agained, publish an announcement...
    //   this->client.publish("outTopic", "hello world");
//       // ... and resubscribe
//       this->client.subscribe("inTopic");
    } else {
      Serial.print(" failed, rc=");
      Serial.print(state());
      Serial.println(" retry in 3 seconds");
      // Wait 3 seconds before retrying
      delay(3000);
    }
  }
}