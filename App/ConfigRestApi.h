#ifndef __CONFIG_REST_API_H__
#define __CONFIG_REST_API_H__

#include "ParkControlState.h"

class ConfigRestApi {
    public:
        ConfigRestApi() {}

        void start(ParkControlState &state);
        void loop();

    private:
        //static ESP8266WebServer *_server;

        static void handleGet();

        static void handleParkControlOn();
        static void handleParkControlOff();
};
#endif
