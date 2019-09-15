#include "AnimationRenderer.h"

#include <vector>

#include "../libraries/Arduino-Log/ArduinoLog.h"

#include "../Animations/PixelRange.h"

template <typename TPixel>
void AnimationRenderer<TPixel>::render(unsigned int deltaTimeMs) {
    Log.verbose("Rendering next frame of animation");

    std::vector<TPixel> pixels = this->_animation.getPixels(deltaTimeMs);
    PixelRange range = this->_animation.getRange();

    for (int idx = 0; idx < (range.end - range.start); idx++) {
        this->_out.setPixelColor(idx + range.start, pixels.at(idx));
    }

    this->_out.show();
}

template class AnimationRenderer<unsigned int>;
