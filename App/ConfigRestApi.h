#ifndef __CONFIG_REST_API_H__
#define __CONFIG_REST_API_H__

#include "ParkControlState.h"
#include "Files.h"

class ConfigRestApi {
    public:
        ConfigRestApi() {}

        void start(ParkControlState &state, Files &files);
        void loop();

    private:
        //static ESP8266WebServer *_server;

        static void handleGet();

        static void handleParkControlOn();
        static void handleParkControlOff();
        static void handleParkControlState();
};
#endif
