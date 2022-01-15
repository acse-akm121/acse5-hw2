#include "filter.h"
#include "image.h"
#include "pixel.h"
#include <cmath>
#include <iostream>

Image ImageFilter::spotlight(Image img, unsigned int centerX, unsigned int centerY) {
    for (unsigned int x = 0; x < img.width(); x++) {
        for (unsigned int y = 0; y < img.height(); y++) {
            Pixel *pixel = img.getPixel(x, y);
            int xdist = x - centerX;
            int ydist = y - centerY;
            double dst = sqrt(pow(xdist, 2) + pow(ydist, 2));
            double max_dst = std::min(img.width()/2, img.height()/2);
            if (dst >= 0.8 * max_dst) {
                dst = 0.8 * max_dst;
            }
            dst = dst / max_dst;
            pixel->l = pixel->l * (1 - dst);
        }
    }
    return img;
}
