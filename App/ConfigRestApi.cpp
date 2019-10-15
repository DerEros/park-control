#include "ConfigRestApi.h"

#include <ESP8266WebServer.h>

#include "../libraries/Arduino-Log/ArduinoLog.h"
#include "../libraries/ArduinoJson/ArduinoJson.h"

ESP8266WebServer *_server;
ParkControlState *_state;
Files *_files;

const char *DISTANCES_CONFIG_FILE_NAME = "distances.json";

bool handleFileRead(String uri) {
    if (uri.endsWith("/")) uri += "index.html";
    String contentType = _files->getContentType(uri);

    String uriGz = uri;
    uriGz.concat(".gz");

    if (_files->fileExists(uriGz)) {
        uri = uriGz;
        _server->sendHeader("Content-Encoding", "gzip");
    }

    if (_files->fileExists(uri)) {
        File file = _files->getFileForRead(uri);
        _server->streamFile(file, contentType);
        file.close();
        return true;
    }

    return false;
}

void ConfigRestApi::start(ParkControlState &state, Files &files) {
    Log.notice("Starting config API\n");

    _state = &state;
    _files = &files;
    _server = new ESP8266WebServer(80);

    _server->on("/", handleGet);    
    _server->onNotFound([]() {
        if (!handleFileRead(_server->uri())) {
            _server->send(404, "text/plain", "File not found");
        }
    });
    _server->on("/parkcontrol/on", handleParkControlOn);
    _server->on("/parkcontrol/off", handleParkControlOff);
    _server->on("/parkcontrol/state", handleParkControlState);
    _server->on("/parkcontrol/distances", handleDistances);
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
    Log.notice("Park control turned on\n");

    _state->parkControlEnabled = true;

    _server->send(200, "text/plain", "OK");
}

void ConfigRestApi::handleParkControlOff() {
    Log.notice("Park control turned off\n");

    _state->parkControlEnabled = false;

    _server->send(200, "text/plain", "OK");
}

void ConfigRestApi::handleParkControlState() {
    Log.notice("Getting park control state\n");

    String result = "";
    result.concat("{\"enabled\":");
    result.concat(_state->parkControlEnabled ? "true" : "false");
    result.concat("}");

    _server->send(200, "application/json", result);
}

void ConfigRestApi::handleDistances() {
    Log.notice("Got request for distances");

    switch (_server->method()) {
        case HTTPMethod::HTTP_POST:
            Log.notice("New distance settings posted");
            handlePostingDistances();
            break;
        case HTTPMethod::HTTP_GET:
            Log.notice("Distance settings request");
            if (_files->fileExists(DISTANCES_CONFIG_FILE_NAME)) {
                Log.trace("Sending stored distance config");
                File distancesConfigFile = _files->getFileForRead(DISTANCES_CONFIG_FILE_NAME);
                _server->streamFile(distancesConfigFile, "application/json");
            } else {
                Log.trace("No stored distance config found, sending defaults");
                String defaultData = "{\"moveCloserDistance\": 100, \"idealDistance\": 80, \"moveFurtherDistance\": 20, \"criticalDistance\": 0}";
                _server->send(200, "application/json", defaultData);
            }

            break;
    }

}

void ConfigRestApi::handlePostingDistances() {
    File distancesConfigFile = _files->getFileForWrite(DISTANCES_CONFIG_FILE_NAME);

    const int capacity = JSON_OBJECT_SIZE(4);
    StaticJsonDocument<capacity> doc;
    DeserializationError err = deserializeJson(doc, _server->arg("plain"));

    int minMoveCloserDistance = doc["move_closer_distance"];
    int minIdealDistance = doc["ideal_distance"];
    int minMoveFurtherDistance = doc["move_further_distance"];
    int minCriticalCloseDistance = doc["critical_distance"];

    Log.notice("New distance values received: (%d, %d, %d, %d) centimeters\n", 
            minMoveCloserDistance, 
            minIdealDistance,
            minMoveFurtherDistance,
            minCriticalCloseDistance);

    serializeJson(doc, distancesConfigFile);

    _server->send(200, "text/plain", "OK");
}
