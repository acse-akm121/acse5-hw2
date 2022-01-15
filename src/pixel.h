#ifndef AKM_PIXEL_H
#define AKM_PIXEL_H

#include <iostream>
#include <sstream>

/*
Class for a HSLA Pixel defined by
H - Hue value
S - Saturation
L - Luminance
A - Alpha
*/
class Pixel {
    public:
        double h;
        double s;
        double l;
        double a;
        Pixel();
        Pixel(double hue, double saturation, double luminance);
        Pixel(double hue, double saturation, double luminance, double alpha);
};

#endif