// #include <ESP8266WiFi.h>
#include <WiFiManager.h>

#define SSID "SynerMycha"

class WIFI {
    public:
        WIFI();
        static boolean isAP;

        boolean isConnected();
        void setup();
    
    private:
        WiFiManager wifiManager;
        static void configModeCallback(WiFiManager *wifi_manager);

};