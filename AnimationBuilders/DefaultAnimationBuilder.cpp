#include "DefaultAnimationBuilder.h"

#include "../Animations/MinimalPixelPattern.h"
#include "../Animations/BlinkAnimation.h"

IAnimation<Pixel> *DefaultAnimationBuilder::getAnimation() {
    MinimalPixelPattern<Pixel> *patternOn = new MinimalPixelPattern<Pixel>(0x00FFDD00);
    MinimalPixelPattern<Pixel> *patternOff = new MinimalPixelPattern<Pixel>(0x000000FF);
    
    BlinkAnimation<Pixel> *animation = new BlinkAnimation<Pixel>(
            PixelRange(0, 7),
            4,
            *patternOn,
            *patternOff
    );

    return animation;
}
