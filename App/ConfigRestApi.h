#ifndef __CONFIG_REST_API_H__
#define __CONFIG_REST_API_H__

class ConfigRestApi {
    public:
        ConfigRestApi() {}

        void start();
        void loop();

    private:
        //static ESP8266WebServer *_server;

        static void handleGet();
};
#endif
