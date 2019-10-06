#include "AnimationRenderer.h"

#include <vector>

#include "../libraries/Arduino-Log/ArduinoLog.h"
#include "../libraries/FastLED/FastLED.h"

#include "../Animations/PixelRange.h"

template <typename TPixel>
void AnimationRenderer<TPixel>::render(unsigned int deltaTimeMs) {
    Log.verbose("Rendering next frame of animation\n");

    std::vector<TPixel> pixels = this->_animation.getPixels(deltaTimeMs);
    PixelRange range = this->_animation.getRange();

    for (int idx = 0; idx <= (range.end - range.start); idx++) {
        this->_out[idx + range.start] = CRGB(pixels.at(idx));
    }

    FastLED.show();
}

template class AnimationRenderer<unsigned int>;
template class AnimationRenderer<CRGB>;
