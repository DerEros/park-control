#include "ConfigRestApi.h"

#include <ESP8266WebServer.h>

#include "../libraries/Arduino-Log/ArduinoLog.h"
#include "../libraries/ArduinoJson/ArduinoJson.h"

#include "FileNames.h"

ESP8266WebServer *_server;
ParkControlState *_state;
HalloweenState *_halloweenState;
Files *_files;

bool handleFileRead(String uri) {
    Log.trace("Trying to read file %s\n", uri.c_str());
    if (uri.endsWith("/")) uri += "index.html";
    String contentType = _files->getContentType(uri);

    String uriGz = uri;
    uriGz.concat(".gz");

    if (_files->fileExists(uriGz)) {
        Log.trace("Found GZ version of file\n");
        uri = uriGz;
    }

    if (_files->fileExists(uri)) {
        Log.trace("Transferring %s\n", uri.c_str());
        File file = _files->getFileForRead(uri);
        _server->streamFile(file, contentType);
        file.close();
        return true;
    }

    return false;
}

void ConfigRestApi::start(ParkControlState &state, HalloweenState &halloweenState, Files &files) {
    Log.notice("Starting config API\n");

    _state = &state;
    _halloweenState = &halloweenState;
    _files = &files;
    _server = new ESP8266WebServer(80);

    _server->onNotFound([]() {
        if (!handleFileRead(_server->uri())) {
            _server->send(404, "text/plain", "File not found");
        }
    });
    _server->on("/parkcontrol/on", handleParkControlOn);
    _server->on("/parkcontrol/off", handleParkControlOff);
    _server->on("/parkcontrol/state", handleParkControlState);
    _server->on("/parkcontrol/distances", handleDistances);
    _server->on("/parkcontrol/animationmode", handleAnimationMode);
    _server->on("/halloween/spookymode/on", handleSpookyModeOn);
    _server->on("/halloween/spookymode/off", handleSpookyModeOff);
    _server->begin();
}

void ConfigRestApi::loop() {
    _server->handleClient();
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
    Log.notice("Got request for distances\n");

    switch (_server->method()) {
        case HTTPMethod::HTTP_POST:
            Log.notice("New distance settings posted\n");
            handlePostingDistances();
            break;
        case HTTPMethod::HTTP_GET:
            Log.notice("Distance settings request\n");
            if (_files->fileExists(DISTANCES_CONFIG_FILE_NAME)) {
                Log.trace("Sending stored distance config\n");
                File distancesConfigFile = _files->getFileForRead(DISTANCES_CONFIG_FILE_NAME);
                _server->streamFile(distancesConfigFile, "application/json");
            } else {
                Log.trace("No stored distance config found, sending defaults\n");
                String defaultData = "{\"moveCloserDistance\": 100, \"idealDistance\": 80, \"moveFurtherDistance\": 20, \"criticalDistance\": 0}";
                _server->send(200, "application/json", defaultData);
            }

            break;
    }

}

void ConfigRestApi::handlePostingDistances() {
    File distancesConfigFile = _files->getFileForWrite(DISTANCES_CONFIG_FILE_NAME);

    char buffer[1024];
    memset(buffer, 0, 1024);
    const int capacity = JSON_OBJECT_SIZE(4);
    StaticJsonDocument<capacity> doc;
    strlcpy(buffer, _server->arg("plain").c_str(), 1023);
    Log.verbose("%s\n", buffer);

    distancesConfigFile.write((const uint8_t *)buffer, strlen(buffer));
    distancesConfigFile.close();

    _server->send(200, "text/plain", "OK");

    DeserializationError err = deserializeJson(doc, buffer);

    int minMoveCloserDistance = doc["moveCloserDistance"];
    int minIdealDistance = doc["idealDistance"];
    int minMoveFurtherDistance = doc["moveFurtherDistance"];
    int minCriticalCloseDistance = doc["criticalDistance"];

    Log.notice("New distance values received: (%d, %d, %d, %d) centimeters\n", 
            minMoveCloserDistance, 
            minIdealDistance,
            minMoveFurtherDistance,
            minCriticalCloseDistance);

    delay(10);
    Log.notice("Restarting to activate new settings\n");

    ESP.restart();
}

void ConfigRestApi::handleAnimationMode() {
    Log.notice("Request for animation mode\n");

    const char* messageBuffer; 
    File animationModeFile;
    switch (_server->method()) {
        case HTTPMethod::HTTP_POST:
            Log.trace("Writing animation mode\n");
            animationModeFile = _files->getFileForWrite(ANIMATION_MODE_CONFIG_FILE_NAME);
            messageBuffer = _server->arg("plain").c_str();
            animationModeFile.write(messageBuffer, strlen(messageBuffer));
            animationModeFile.close();
            _server->send(202, "text/plain", "OK");
            break;
        case HTTPMethod::HTTP_GET:
            Log.trace("Reading animation mode\n");
            if (_files->fileExists(ANIMATION_MODE_CONFIG_FILE_NAME)) {
                animationModeFile = _files->getFileForRead(ANIMATION_MODE_CONFIG_FILE_NAME);
                _server->streamFile(animationModeFile, "application/json");
                animationModeFile.close();
            } else {
                _server->send(200, "application/json", "{\"animationMode\":0}");
            }
            break;
    }

}

void ConfigRestApi::handleSpookyModeOn() {
    Log.trace("Spooky mode on\n");
    _halloweenState->spookyMode = true;
    _server->send(200, "text/plain", "OK\nSpooky mode on");
}

void ConfigRestApi::handleSpookyModeOff() {
    Log.trace("Spooky mode off\n");
    _halloweenState->spookyMode = false;
    _server->send(200, "text/plain", "OK\nSpooky mode off");
}
