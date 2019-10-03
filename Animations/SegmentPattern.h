#ifndef __SEGMENT_PATTERN_H__
#define  __SEGMENT_PATTERN_H__

#include "IPixelPattern.h"

#include <vector>
#include <numeric>

template <typename TPixel>
class SegmentPattern : public IPixelPattern<TPixel> {
    public:
        struct Segment {
            unsigned int numPixels;
            TPixel color;

            Segment(unsigned int n, TPixel c) : numPixels(n), color(c) {}
        };

        SegmentPattern(std::vector<Segment> segments) : _segments(segments) {
            _totalPatternSize = std::accumulate(
                            _segments.begin(), _segments.end(), 0,
                            [](unsigned int acc, Segment s) { return acc += s.numPixels; }
                    );
        }

        unsigned int getLength() { return _totalPatternSize; }
        const TPixel getPixel(int index) const;

    private:
        std::vector<Segment> _segments;
        unsigned int _totalPatternSize;
};

#endif
