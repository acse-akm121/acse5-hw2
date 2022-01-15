#include "pixel.h"

Pixel::Pixel() {
    h = 0.0;
    s = 0.0;
    l = 0.0;
    a = 1.0;
}

Pixel::Pixel(double hue, double saturation, double luminance) {
    h = hue;
    s = saturation;
    l = luminance;
}

Pixel::Pixel(double hue, double saturation, double luminance, double alpha) {
    h = hue;
    s = saturation;
    l = luminance;
    a = alpha;
}