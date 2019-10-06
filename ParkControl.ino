#include "libraries/Arduino-Log/ArduinoLog.h"

#include "App/App.h"

App app;

void setup() {
    app.init();    
}

void loop() {
    app.loop();
}
