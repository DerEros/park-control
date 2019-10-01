#include "PeriodicMeasurement.h"

void PeriodicMeasurement::measure(int timeElapsed) {
    millisSinceLastMeasurement += timeElapsed;

    if (millisSinceLastMeasurement > triggerPeriodMillis) {
        measureNow();
        resetTimer();
    }
}

void PeriodicMeasurement::measureNow() {
   this->lastDistanceCM = us->read(); 
}

void PeriodicMeasurement::resetTimer() {
    millisSinceLastMeasurement %= triggerPeriodMillis;
}
