#ifndef AKM_IMAGEFILTER_H
#define AKM_IMAGEFILTER_H

#include "image.h"
#include "pixel.h"
#include <cmath>
#include <iostream>

class ImageFilter {
    public:
        /*
        Adds a spotlight filter at (centerX, centerY). Increases brightness of pixels
        proportionately to distance from the center.
        */
        Image spotlight(Image img, unsigned int centerX, unsigned int centerY);
};

#endif