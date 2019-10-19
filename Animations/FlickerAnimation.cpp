#include "FlickerAnimation.h"

#include <ArduinoLog.h>

void FlickerAnimation::handleSwitchFrame() {
    Log.verbose("Handling switch frame\n");
    _framePixels.clear();

    for (unsigned idx = 0; idx < getRange().length(); idx++) {
        uint8_t rndIdx = random8();
        _framePixels.push_back(ColorFromPalette(_palette, rndIdx));
    }
}

std::vector<CRGB> FlickerAnimation::getFramePixels() {
    return _framePixels;
}
