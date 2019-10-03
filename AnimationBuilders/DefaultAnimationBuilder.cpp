#include "DefaultAnimationBuilder.h"

#include "../Animations/MinimalPixelPattern.h"
#include "../Animations/RepeatingPixelPattern.h"
#include "../Animations/BlinkAnimation.h"

IAnimation<Pixel> *DefaultAnimationBuilder::getAnimation() {
    IPixelPattern<Pixel> *patternOn = new RepeatingPixelPattern<Pixel>(new MinimalPixelPattern<Pixel>(0x00FFDD00));
    IPixelPattern<Pixel> *patternOff = new RepeatingPixelPattern<Pixel>(new MinimalPixelPattern<Pixel>(0x000000FF));
    
    BlinkAnimation<Pixel> *animation = new BlinkAnimation<Pixel>(
            PixelRange(0, 8),
            4,
            *patternOn,
            *patternOff
    );

    return animation;
}
