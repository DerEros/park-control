#include "HalloweenAnimationBuilder.h"

#include "../libraries/Arduino-Log/ArduinoLog.h"

#include "../Animations/ConditionalAnimation.h"
#include "../Animations/FlickerAnimation.h"

DEFINE_GRADIENT_PALETTE(regularPaletteDef) {
    0,   0,   0,   0,
    190, 255, 35,   5,
    255, 228, 180, 6
};

DEFINE_GRADIENT_PALETTE(spookyPaletteDef) {
    0,   0,   0,   0,
    137, 4, 129,   0,
    255, 162, 3, 224 
};

IStatefulAnimation<Pixel, HalloweenState>* HalloweenAnimationBuilder::getStatefulAnimation(HalloweenState &state) {
    Log.notice("Creating Halloween animation\n");

    Log.trace("Building palettes\n");
    CRGBPalette256 regularPalette = regularPaletteDef;
    CRGBPalette256 spookyPalette = spookyPaletteDef;

    PixelRange pixelRange = PixelRange(0, 8);

    Log.trace("Instantiating animation\n");
    IAnimation<Pixel> *regularFlickerAnimation = new FlickerAnimation(regularPalette, pixelRange, 20, 30);
    IAnimation<Pixel> *spookyFlickerAnimation = new FlickerAnimation(spookyPalette, pixelRange, 20, 30);

    ConditionalAnimation<Pixel, HalloweenState>* halloweenAnimation =
        new ConditionalAnimation<Pixel, HalloweenState>(pixelRange, state);

    halloweenAnimation->addCondition(
            [=](const HalloweenState& state) { return !state.spookyMode; },
            regularFlickerAnimation);

    halloweenAnimation->addCondition(
            [=](const HalloweenState &state) { return state.spookyMode; },
            spookyFlickerAnimation);

    return halloweenAnimation;
}
