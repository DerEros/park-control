#include "ConfigRestApi.h"

#include <ESP8266WebServer.h>

#include "../libraries/Arduino-Log/ArduinoLog.h"
ESP8266WebServer *_server;

void ConfigRestApi::start() {
    Log.notice("Starting config API\n");

    _server = new ESP8266WebServer(80);

    _server->on("/", handleGet);    
    _server->begin();
}

void ConfigRestApi::loop() {
    _server->handleClient();
}

void ConfigRestApi::handleGet() {
    Log.notice("Received Get request\n");

    _server->send(200, "text/plain", "Hello Park Control!");
}
