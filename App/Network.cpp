#include "Network.h"

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <wpa2_enterprise.h>

#include "../libraries/Arduino-Log/ArduinoLog.h"

const char* ssid = "ssid";
const char* username = "user";
const char* pwd = "pwd";
const char* dnsName = "ParkControl";

void Network::start() {
    Log.notice("Starting network\n");

    Serial.setDebugOutput(true);


    wifi_set_opmode(STATION_MODE);
    struct station_config stationConf;
    memset(&stationConf, 0, sizeof(stationConf));
    strlcpy((char*)&stationConf.ssid, ssid, 32);
    strlcpy((char*)&stationConf.password, pwd, 64);
    wifi_station_set_config(&stationConf);

    wifi_station_clear_cert_key();
    wifi_station_clear_enterprise_ca_cert();

    wifi_station_set_wpa2_enterprise_auth(1);
    wifi_station_set_enterprise_identity((unsigned char*)username, strlen(username));
    wifi_station_set_enterprise_username((unsigned char*)username, strlen(username));
    wifi_station_set_enterprise_password((unsigned char*)pwd, strlen(pwd));
    wifi_station_connect();
    
    Log.notice("... \n");
    //WiFi.printDiag(Serial);
    Log.notice("... \n");

    //WiFi.begin(ssid, pwd);
    Log.trace("Attempting connection to WiFi ");

    while (WiFi.status() != WL_CONNECTED) {
        Log.trace(".");
        delay(500);
    }

    Log.trace(" connected! \n");
    Log.trace("IP Address: \n");
    Log.trace(WiFi.localIP().toString().c_str());

    MDNS.begin(dnsName);
}
