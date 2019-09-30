#include "PeriodicMeasurement.h"

void PeriodicMeasurement::measure(int timeElapsed) {
    millisSinceLastMeasurement += timeElapsed;

    if (millisSinceLastMeasurement > triggerPeriodMillis) {
        measureNow();
        resetTimer();
    }
}

void PeriodicMeasurement::measureNow() {

}

void PeriodicMeasurement::resetTimer() {
    millisSinceLastMeasurement %= triggerPeriodMillis;
}
