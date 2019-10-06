#ifndef __CLOCK_H__
#define  __CLOCK_H__

#include <Arduino.h>

class Clock {
    public:
        Clock() : _lastMillis(millis()) {}

        unsigned long getElapsedTimeMillisAndReset() { 
            unsigned long currentTime = millis();
            unsigned long elapsedTime = currentTime - _lastMillis;
            reset();
            return elapsedTime;
        }
        void reset() { _lastMillis = millis(); }
    private:
        unsigned long _lastMillis;
};

#endif
