#ifndef __PERIODIC_MEASUREMENT_H__
#define __PERIODIC_MEASUREMENT_H__

#include "Arduino.h"
#include "../libraries/Ultrasonic/src/Ultrasonic.h"

class PeriodicMeasurement {
    public:

        PeriodicMeasurement(int trigger, int echo, int periodMillis, int offsetMillis, int timeoutMillis = 40) {
            triggerPeriodMillis = periodMillis;
            millisSinceLastMeasurement = -offsetMillis;

            us = new Ultrasonic(trigger, echo, timeoutMillis * 1000);
        }

        ~PeriodicMeasurement() {
            delete us;
        }

        float getLastDistanceCM() { return this->lastDistanceCM; }
        void measure(int timeElapsed);

    private:
        int triggerPeriodMillis;

        float lastDistanceCM = 0;
        int millisSinceLastMeasurement;

        Ultrasonic *us;

        void measureNow();
        void resetTimer();
};

#endif
