#include "DefaultAnimationBuilder.h"

#include <vector>

#include "../Animations/MinimalPixelPattern.h"
#include "../Animations/SegmentPattern.h"
#include "../Animations/RepeatingPixelPattern.h"
#include "../Animations/BlinkAnimation.h"
#include "../Animations/SlideAnimation.h"

IAnimation<Pixel> *DefaultAnimationBuilder::getAnimation() {
    std::vector<SegmentPattern<Pixel>::Segment> segments {
                    SegmentPattern<Pixel>::Segment(1, 0x0000FF00),
                    SegmentPattern<Pixel>::Segment(1, 0x00009900),
                    SegmentPattern<Pixel>::Segment(1, 0x00002200),
                    SegmentPattern<Pixel>::Segment(1, 0x00001200),
                    SegmentPattern<Pixel>::Segment(9, 0)
    };

    IPixelPattern<Pixel> *pattern = new RepeatingPixelPattern<Pixel>(new SegmentPattern<Pixel>(segments));

    SlideAnimation<Pixel> *animation = new SlideAnimation<Pixel>(
            PixelRange(0, 8),
            24,
            *pattern,
            SlideAnimation<Pixel>::RIGHT_TO_LEFT
    );

    return animation;
}
