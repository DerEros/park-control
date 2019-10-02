#ifndef __PERIODIC_MEASUREMENT_H__
#define __PERIODIC_MEASUREMENT_H__

#include "Arduino.h"

class PeriodicMeasurement {
    public:

        PeriodicMeasurement(int trigger, int echo, int periodMillis, int offsetMillis, int timeoutMillis = 40) {
            triggerPeriodMillis = periodMillis;
            millisSinceLastMeasurement = -offsetMillis;

            this->triggerPin = trigger;
            this->echoPin = echo;
            init();
        }

        ~PeriodicMeasurement() {
        }

        float getLastDistanceCM();
        void measure(int timeElapsed);

    private:
        int triggerPeriodMillis;

        int millisSinceLastMeasurement;

        int triggerPin;
        int echoPin;

        void measureNow();
        void resetTimer();

        void init();
        float distanceCM = 0.0;
        volatile unsigned long pulseBegin = 0;
        volatile bool measureInProgress = false;
        static void handleTriggerRise(PeriodicMeasurement *self);
        static void handleTriggerFall(PeriodicMeasurement *self);
};

#endif
