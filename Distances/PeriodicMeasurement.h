#ifndef __PERIODIC_MEASUREMENT_H__
#define __PERIODIC_MEASUREMENT_H__

#include "Arduino.h"

class PeriodicMeasurement {
    public:

        PeriodicMeasurement(int trigger, int echo, int periodMillis, int offsetMillis, int timeoutMillis = 40) {
            this->triggerPeriodMillis = periodMillis;
            this->millisSinceLastMeasurement = -offsetMillis;

            this->triggerPin = trigger;
            this->echoPin = echo;
            this->echoInterrupt = digitalPinToInterrupt(this->echoPin);

            init();
        }

        float getLastDistanceCM();
        void measure(int timeElapsed);

    private:
        float distanceCM = 0.0;
        volatile unsigned long pulseBeginMicros = 0;
        volatile bool measureInProgress = false;

        // How long to wait before running the next distance scan
        int triggerPeriodMillis;

        int millisSinceLastMeasurement;

        int triggerPin;
        int echoPin;
        int echoInterrupt;

        void init();

        void measureNow();
        void resetTimer();

        static void handleTriggerRise(PeriodicMeasurement *self);
        static void handleTriggerFall(PeriodicMeasurement *self);
};

#endif
