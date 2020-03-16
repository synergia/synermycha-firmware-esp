#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define MQTT_SERVER_IP "192.168.1.100"
#define MQTT_SERVER_PORT 1883
#define MQTT_CLIENT_ID "SynerMycha"
#define MSG_BUFFER_SIZE	(50)


class MQTTClient : public PubSubClient {
    public:
        MQTTClient();

        const char* mqtt_server;

        void setup();
        void reconnect();
        void assureConnection();

    private:
    //     WiFiManager wifiManager;
        WiFiClient wifi_client;

        static void callback(char* topic, byte* payload, unsigned int length);

};