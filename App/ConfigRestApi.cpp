#include "ConfigRestApi.h"

#include <ESP8266WebServer.h>

#include "../libraries/Arduino-Log/ArduinoLog.h"
ESP8266WebServer *_server;
ParkControlState *_state;

void ConfigRestApi::start(ParkControlState &state) {
    Log.notice("Starting config API\n");

    _state = &state;
    _server = new ESP8266WebServer(80);

    _server->on("/", handleGet);    
    _server->on("/parkcontrol/on", handleParkControlOn);
    _server->on("/parkcontrol/off", handleParkControlOff);
    _server->begin();
}

void ConfigRestApi::loop() {
    _server->handleClient();
}

void ConfigRestApi::handleGet() {
    Log.notice("Received Get request\n");

    _server->send(200, "text/plain", "Hello Park Control!");
}

void ConfigRestApi::handleParkControlOn() {
    Log.notice("Park control turned on");

    _state->parkControlEnabled = true;

    _server->send(200, "text/plain", "OK");
}

void ConfigRestApi::handleParkControlOff() {
    Log.notice("Park control turned off");

    _state->parkControlEnabled = false;

    _server->send(200, "text/plain", "OK");
}
