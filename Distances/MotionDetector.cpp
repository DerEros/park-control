#include "MotionDetector.h"

#include <cstdlib>
#include "../libraries/Arduino-Log/ArduinoLog.h"

void MotionDetector::sample(unsigned int timeSinceLastSampleMillis, unsigned int value) {
    addValueToAverage(value);
    detectAndHandleTimeout(timeSinceLastSampleMillis); 
}

void MotionDetector::addValueToAverage(unsigned int value) {
    Log.verbose("MotionDetector: %d -> (%d, %F) \n", value, _numSamples, _currentAverage);
    _numSamples++; 
    if (_numSamples == 1) {
        _currentAverage = value;
    } else {
       _currentAverage *= (float)(_numSamples - 1) / (float)_numSamples;
       _currentAverage += (float)value / (float)_numSamples;
    }
}

void MotionDetector::detectAndHandleTimeout(unsigned int timeSinceLastSampleMillis) {
    if (_timeSinceResetMillis + timeSinceLastSampleMillis >= _samplingTimeMillis) {
        reset();
    } else {
        _timeSinceResetMillis += timeSinceLastSampleMillis;
    }
}

float MotionDetector::getAverage() {
    return _currentAverage;
}

void MotionDetector::reset() {
    _timeSinceResetMillis = 0;
    _oldestAverage = _previousAverage;
    _previousAverage = _currentAverage;
    _currentAverage = 0.0;
    _numSamples = 0;
}

bool MotionDetector::isMovementDetected() {
    return abs(_oldestAverage - _previousAverage) > _detectionThreshold;
}
