#ifndef __CLOCK_H__
#define  __CLOCK_H__

#include <Arduino.h>

class Clock {
    public:
        Clock() : _lastMillis(millis()) {}

        unsigned long getElapsedTimeMillis() { return millis() - _lastMillis; }
        void reset() { _lastMillis = millis(); }
    private:
        unsigned long _lastMillis;
};

#endif
