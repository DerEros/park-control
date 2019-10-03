#include "PeriodicMeasurement.h"

typedef void(*IsrWithArg)(void*);

void PeriodicMeasurement::init() {
    pinMode(this->echoPin, INPUT);
    pinMode(this->triggerPin, OUTPUT);
    digitalWrite(this->triggerPin, LOW);

    attachInterruptArg(digitalPinToInterrupt(echoPin), (IsrWithArg)handleTriggerRise, this, RISING);
}

void PeriodicMeasurement::measure(int timeElapsed) {
    millisSinceLastMeasurement += timeElapsed;

    if ((millisSinceLastMeasurement > triggerPeriodMillis) &&  !measureInProgress) {
        measureNow();
        resetTimer();
    }
}

void PeriodicMeasurement::measureNow() {
    measureInProgress = true;
    digitalWrite(this->triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->triggerPin, LOW);
}

void PeriodicMeasurement::resetTimer() {
    millisSinceLastMeasurement %= triggerPeriodMillis;
}

float PeriodicMeasurement::getLastDistanceCM() {
    return this->distanceCM;
}

void ICACHE_RAM_ATTR PeriodicMeasurement::handleTriggerRise(PeriodicMeasurement *self) {
    self->pulseBeginMicros = micros();

    attachInterruptArg(self->echoInterrupt, (IsrWithArg)handleTriggerFall, self, FALLING);
}

void ICACHE_RAM_ATTR PeriodicMeasurement::handleTriggerFall(PeriodicMeasurement *self) {
    unsigned long m = micros();
    float timeOneWay = ((float)m - self->pulseBeginMicros) / 2.0;
    self->distanceCM = 0.0340 * timeOneWay;

    attachInterruptArg(self->echoInterrupt, (IsrWithArg)handleTriggerRise, self, RISING);
    self->measureInProgress = false;
}
