#ifndef __I_PIXEL_PATTERN_H__
#define __I_PIXEL_PATTERN_H__

template<typename TPixel>
class IPixelPattern {
    public:
        virtual unsigned int getLength() = 0;
        virtual const TPixel getPixel(int index) const = 0;
};

#endif
