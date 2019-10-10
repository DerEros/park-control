#include "ConfigRestApi.h"

#include <ESP8266WebServer.h>

#include "../libraries/Arduino-Log/ArduinoLog.h"
ESP8266WebServer *_server;
ParkControlState *_state;
Files *_files;

void ConfigRestApi::start(ParkControlState &state, Files &files) {
    Log.notice("Starting config API\n");

    _state = &state;
    _files = &files;
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

    if (_files->fileExists("/index.html")) {
        File file = _files->getFileForRead("/index.html");
        _server->streamFile(file, _files->getContentType("/index.html"));
        file.close();
    } else {
        _server->send(404, "text/plain", "File not found");
    }
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
