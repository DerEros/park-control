#include "BlinkAnimation.h"

#include "../libraries/Arduino-Log/ArduinoLog.h"

template <typename TPixel>
std::vector<TPixel> BlinkAnimation<TPixel>::getPixels(unsigned int msSinceLastCall) {
    _timePassendInPhase += msSinceLastCall;

    if (static_cast<float>(_timePassendInPhase) > _phaseTimeInMs) {
        switchAnimationPhase(); 
        resetPhaseTime();
    }
}

template <typename TPixel>
void BlinkAnimation<TPixel>::switchAnimationPhase() {
    Log.verbose("Switching blink animation phase");
    
    if (_blinkPhase == ON) {
        _blinkPhase = OFF; 
    } else {
        _blinkPhase = ON; 
    }
}

template <typename TPixel>
void BlinkAnimation<TPixel>::resetPhaseTime() {
    while (static_cast<float>(_timePassendInPhase) > _phaseTimeInMs) {
        _timePassendInPhase -= _phaseTimeInMs;
    }
}
