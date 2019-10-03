#ifndef __PIXEL_RANGE_H__
#define __PIXEL_RANGE_H__

struct PixelRange {
    int start;
    int end;

    PixelRange(int start, int end) : start(start), end(end) {}
    int length() const { return end - start; }
};

#endif
