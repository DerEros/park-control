#include "DefaultAnimationBuilder.h"

#include <vector>

#include "../Animations/MinimalPixelPattern.h"
#include "../Animations/SegmentPattern.h"
#include "../Animations/RepeatingPixelPattern.h"
#include "../Animations/BlinkAnimation.h"

IAnimation<Pixel> *DefaultAnimationBuilder::getAnimation() {
    IPixelPattern<Pixel> *patternOn = new RepeatingPixelPattern<Pixel>(new MinimalPixelPattern<Pixel>(0x00FFDD00));
//    IPixelPattern<Pixel> *patternOff = new RepeatingPixelPattern<Pixel>(new MinimalPixelPattern<Pixel>(0x000000FF));

    std::vector<SegmentPattern<Pixel>::Segment> segments {
                    SegmentPattern<Pixel>::Segment(1, 0x0000FF00),
                    SegmentPattern<Pixel>::Segment(1, 0),
                    SegmentPattern<Pixel>::Segment(1, 0x00FF00FF)
    };

    IPixelPattern<Pixel> *patternOff = new RepeatingPixelPattern<Pixel>(new SegmentPattern<Pixel>(segments));
    
    BlinkAnimation<Pixel> *animation = new BlinkAnimation<Pixel>(
            PixelRange(0, 8),
            1,
            *patternOn,
            *patternOff
    );

    return animation;
}
