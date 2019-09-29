#ifndef __PERIODIC_MEASUREMENT_H__
#define __PERIODIC_MEASUREMENT_H__

class PeriodicMeasurement {
    public:
        enum Unit {
            MM,
            CM,
            M
        };

        PeriodicMeasurement(int trigger, int echo, int periodMillis, int offsetMillis, int timeoutMillis) {
            triggerPin = trigger;
            echoPin = echo;
            triggerPeriodMillis = periodMillis;
            triggerOffsetMillis = offsetMillis;
            echoTimeoutMillis = timeoutMillis;
        }

        float lastDistance() { return lastDistance(CM); }
        float lastDistance(Unit unit);

    private:
        int triggerPin;
        int echoPin;
        int triggerPeriodMillis;
        int triggerOffsetMillis;
        int echoTimeoutMillis;

        int lastDistanceMillis = 0;
        int millisSinceLastMeasurement = 0;
};

#endif
