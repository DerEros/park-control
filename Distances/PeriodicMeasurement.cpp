#include "PeriodicMeasurement.h"

void PeriodicMeasurement::measure(int timeElapsed) {
    millisSinceLastMeasurement += timeElapsed;

    if ((millisSinceLastMeasurement > triggerPeriodMillis) &&  !measureInProgress) {
        measureNow();
        resetTimer();
    }
}

void PeriodicMeasurement::init() {
    pinMode(this->echoPin, INPUT);
    pinMode(this->triggerPin, OUTPUT);
    digitalWrite(this->triggerPin, LOW);

    attachInterruptArg(digitalPinToInterrupt(echoPin), (void (*)(void*))handleTriggerRise, this, RISING);
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
    unsigned long m = micros();
    self->pulseBegin = micros();

    detachInterrupt(digitalPinToInterrupt(self->echoPin));
    attachInterruptArg(digitalPinToInterrupt(self->echoPin), (void(*)(void*))handleTriggerFall, self, FALLING);
}

void ICACHE_RAM_ATTR PeriodicMeasurement::handleTriggerFall(PeriodicMeasurement *self) {
    unsigned long m = micros();
    float timeOneWay = ((float)m - self->pulseBegin) / 2.0;

    self->distanceCM = 340.0 * timeOneWay / 10000;

    detachInterrupt(digitalPinToInterrupt(self->echoPin));
    attachInterruptArg(digitalPinToInterrupt(self->echoPin), (void(*)(void*))handleTriggerRise, self, RISING);

    self->measureInProgress = false;
}
