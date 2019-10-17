#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "../libraries/Arduino-Log/ArduinoLog.h"
#include "../libraries/ArduinoJson/ArduinoJson.h"

#include "Files.h"
#include "FileNames.h"

class Config {
    public:
        Config() {
            numLeds = 8;
            minMoveFurtherDistance = 50;
            minIdealDistance = 40;
            minMoveFurtherDistance = 15;
            minCriticalCloseDistance = 0;

            animationFps = 24;

            inactiveTimeout = 5000;
        }

        void load(Files &files) {
            Log.notice("Loading config\n");
            if (files.fileExists(DISTANCES_CONFIG_FILE_NAME)) {
                Log.trace("Found distances config file: %s\n", DISTANCES_CONFIG_FILE_NAME);
                File distancesFile = files.getFileForRead(DISTANCES_CONFIG_FILE_NAME);
                
                char buffer[1024];
                memset((void*)buffer, 0, 1024);
                distancesFile.read((uint8_t*)buffer, 1024);
                Log.trace("Distances file content: %s\n", buffer);
                const size_t capacity = JSON_OBJECT_SIZE(4);
                StaticJsonDocument<capacity> doc;
                DeserializationError err = deserializeJson(doc, buffer);
                if (err) {
                    Log.error("Error deserializing config file: %s\n", err.c_str());
                }

                setMinMoveCloserDistance(doc["moveCloserDistance"]);
                setMinIdealDistance(doc["idealDistance"]);
                setMinMoveFurtherDistance(doc["moveFurtherDistance"]);
                setMinCriticalCloseDistance(doc["criticalDistance"]);

                Log.trace("Loaded distances (%d, %d, %d, %d)\n",
                        minMoveCloserDistance,
                        minIdealDistance,
                        minMoveFurtherDistance,
                        minCriticalCloseDistance);
            } else {
                Log.trace("Distances config file not found (%s)\n", DISTANCES_CONFIG_FILE_NAME);
            }

            if (files.fileExists(PIXEL_CONFIG_FILE_NAME)) {
                Log.trace("Found pixel config file: %s\n", PIXEL_CONFIG_FILE_NAME);
            } else {
                Log.trace("Could not find pixel config file %s\n", PIXEL_CONFIG_FILE_NAME);
            }
        };

        unsigned int getNumLeds() { return numLeds; }
        unsigned int getMinMoveCloserDistance() { return minMoveCloserDistance; }
        unsigned int getMinIdealDistance() { return minIdealDistance; }
        unsigned int getMinMoveFurtherDistance() { return minMoveFurtherDistance; }
        unsigned int getMinCriticalCloseDistance() { return minCriticalCloseDistance; }

        unsigned int getAnimationFps() { return animationFps; }

        unsigned int getInactiveTimeout() { return inactiveTimeout; }

        void setNumLeds(unsigned int m) { numLeds = m; }
        void setMinMoveCloserDistance(unsigned int m) { minMoveCloserDistance = m; }
        void setMinIdealDistance(unsigned int m) { minIdealDistance = m; }
        void setMinMoveFurtherDistance(unsigned int m) { minMoveFurtherDistance = m; }
        void setMinCriticalCloseDistance(unsigned int m) { minCriticalCloseDistance = m; }
    private:
        unsigned int numLeds;
        unsigned int minMoveCloserDistance;
        unsigned int minIdealDistance;
        unsigned int minMoveFurtherDistance;
        unsigned int minCriticalCloseDistance;

        unsigned int animationFps;

        unsigned int inactiveTimeout;
};
#endif
