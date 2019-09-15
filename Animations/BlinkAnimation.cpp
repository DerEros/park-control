#include "BlinkAnimation.h"

#include "../libraries/Arduino-Log/ArduinoLog.h"

template class BlinkAnimation<uint32_t>;

template <typename TPixel>
std::vector<TPixel> BlinkAnimation<TPixel>::getPixels(unsigned int msSinceLastCall) {
    _timePassendInPhase += msSinceLastCall;

    if (static_cast<float>(_timePassendInPhase) > _phaseTimeInMs) {
        switchAnimationPhase(); 
        resetPhaseTime();
    }

    switch (_blinkPhase) {
        case ON:
            return readPixels(_patternOn);
        case OFF:
        default:
            return readPixels(_patternOff);
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

template <typename TPixel>
std::vector<TPixel> BlinkAnimation<TPixel>::readPixels(const IPixelPattern<TPixel> &pattern) {
    std::vector<TPixel> pixels;
    for (int idx = this->getRange().start; idx < this->getRange().end; idx++) {
        pixels.push_back(pattern.getPixel(idx));
    }

    return pixels;
}
