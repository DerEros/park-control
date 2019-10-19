#include "HalloweenAnimationBuilder.h"

#include "../libraries/Arduino-Log/ArduinoLog.h"

#include "../Animations/FlickerAnimation.h"

DEFINE_GRADIENT_PALETTE(paletteDef) {
    0,   0,   0,   0,
    190, 255, 35,   5,
    255, 228, 180, 6
};

IAnimation<Pixel>* HalloweenAnimationBuilder::getAnimation() {
    Log.notice("Creating Halloween animation\n");

    Log.trace("Building palette\n");
    CRGBPalette256 palette = paletteDef;

    Log.trace("Instantiating animation\n");
    IAnimation<Pixel> *animation = new FlickerAnimation(palette, PixelRange(0, 8), 20, 30);

    return animation;
}
