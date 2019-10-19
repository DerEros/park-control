#include "HalloweenAnimationBuilder.h"

#include "../libraries/Arduino-Log/ArduinoLog.h"

#include "../Animations/FlickerAnimation.h"

DEFINE_GRADIENT_PALETTE(paletteDef) {
    0,   0,   0,   0,
    188, 255, 10,   6,
    255, 228, 235, 6
};

IAnimation<Pixel>* HalloweenAnimationBuilder::getAnimation() {
    Log.notice("Creating Halloween animation\n");

    Log.trace("Building palette\n");
    CRGBPalette256 palette = paletteDef;

    Log.trace("Instantiating animation\n");
    IAnimation<Pixel> *animation = new FlickerAnimation(palette, PixelRange(0, 3), 9);

    return animation;
}
