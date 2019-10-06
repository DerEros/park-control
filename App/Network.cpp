#include "Network.h"

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>

#include "../libraries/Arduino-Log/ArduinoLog.h"

const char* ssid = "SSID";
const char* pwd = "PWD";
const char* dnsName = "ParkControl";

void Network::start() {
    Log.notice("Starting network\n");

    Serial.setDebugOutput(true);

    Log.notice("... \n");
    WiFi.printDiag(Serial);
    Log.notice("... \n");
    WiFi.begin(ssid, pwd);
    Log.trace("Attempting connection to WiFi ");

    while (WiFi.status() != WL_CONNECTED) {
        Log.trace(".");
        delay(500);
    }

    Log.trace(" connected! \n");
    Serial.printf("IP Address: \n");
    Serial.println(WiFi.localIP());

    MDNS.begin(dnsName);
}
