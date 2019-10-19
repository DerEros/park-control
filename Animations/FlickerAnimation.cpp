#include "FlickerAnimation.h"

#include <ArduinoLog.h>

void FlickerAnimation::handleSwitchFrame() {
    Log.verbose("Handling switch frame\n");

    while (_paletteIdx.size() < getRange().length()) {
            _paletteIdx.push_back(random8());
    }

    flicker();
}

std::vector<CRGB> FlickerAnimation::getFramePixels() {
    return _framePixels;
}

void FlickerAnimation::flicker() {
    _framePixels.clear();

    for (unsigned int idx = 0; idx < getRange().length(); idx++) {
        int8_t change = random8(_flickerRate);
        change -= _flickerRate / 2;

        _paletteIdx[idx] += change;
        _framePixels.push_back(ColorFromPalette(_palette, _paletteIdx[idx]));
    }
}
