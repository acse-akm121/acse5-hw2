#include "image.h"
#include "rgb_hsl.h"
#include "lodepng/lodepng.h"
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cerr;
using std::endl;

/*
----------------------------------------
----CONSTRUCTORS AND DESTRUCTORS--------
----------------------------------------
*/

Image::Image() {
    width_ = 0;
    height_ = 0;
    imageData_ = nullptr;
}

Image::Image(unsigned int width, unsigned int height) {
    width_ = width;
    height_ = height;
    imageData_ = new Pixel[width_ * height_];
}

Image::Image(Image const & other) {
    imageData_ = nullptr;
    _copy(other);
}

Image::~Image() {
    delete[] imageData_;
}

void Image::_copy(Image const & other) {
    // Delete self, then copy
    delete[] imageData_;

    width_ = other.width_;
    height_ = other.height_;
    imageData_ = new Pixel[width_ * height_];

    for (unsigned int i = 0; i < width_ * height_; i++) {
        imageData_[i] = other.imageData_[i];
    }
}

/*
----------------------------------------
---------ACCESSORS----------------------
----------------------------------------
*/

unsigned int Image::width() const {
    return width_;
}

unsigned int Image::height() const {
    return height_;
}

Pixel * Image::getPixel(unsigned int x, unsigned int y) {
    if (width_ == 0 || height_ == 0) {
        cerr << "getPixel() called on empty image, returning nullptr" << endl;
        return nullptr;
    }

    if (x >= width_) {
        cerr << "WARNING: Call to cs225::PNG::getPixel(" << x << "," << y << ") tries to access x=" << x
            << ", which is outside of the image (image width: " << width_ << ")." << endl;
        cerr << "       : Truncating x to " << (width_ - 1) << endl;
        x = width_ - 1;
    }

    if (y >= height_) {
        cerr << "WARNING: Call to cs225::PNG::getPixel(" << x << "," << y << ") tries to access y=" << y
            << ", which is outside of the image (image height: " << height_ << ")." << endl;
        cerr << "       : Truncating y to " << (height_ - 1) << endl;
        y = height_ - 1;
    }
    
    unsigned index = x + (y * width_);
    return imageData_ + index;
}

/*
----------------------------------------
---------FILE I/O-----------------------
----------------------------------------
*/

// Read and write in RGB but convert to HSL for filter
bool Image::readFromFile(string const & filename) {
    vector <unsigned char> byteData;
    unsigned err = lodepng::decode(byteData, width_, height_, filename);

    if (err) {
        cerr << "Decoder error: " << err << ": " << lodepng_error_text(err) << endl;
        return false;
    }
    delete[] imageData_;
    imageData_ = new Pixel[width_ * height_];

    for (unsigned int i = 0; i < byteData.size(); i += 4) {
        rgbaColor rgb;
        rgb.r = byteData[i];
        rgb.g = byteData[i + 1];
        rgb.b = byteData[i + 2];
        rgb.a = byteData[i + 3];

        hslaColor hsl = rgb2hsl(rgb);
        Pixel & pixel = imageData_[i/4];
        pixel.h = hsl.h;
        pixel.s = hsl.s;
        pixel.l = hsl.l;
        pixel.a = hsl.a;
    }
    return true;
}

bool Image::writeToFile(string const & filename) {
    unsigned char *byteData = new unsigned char[width_ * height_ * 4];

    for (unsigned i = 0; i < width_ * height_; i++) {
      hslaColor hsl;
      hsl.h = imageData_[i].h;
      hsl.s = imageData_[i].s;
      hsl.l = imageData_[i].l;
      hsl.a = imageData_[i].a;

      rgbaColor rgb = hsl2rgb(hsl);

      byteData[(i * 4)]     = rgb.r;
      byteData[(i * 4) + 1] = rgb.g;
      byteData[(i * 4) + 2] = rgb.b;
      byteData[(i * 4) + 3] = rgb.a;
    }

    unsigned error = lodepng::encode(filename, byteData, width_, height_);
    if (error) {
      cerr << "PNG encoding error " << error << ": " << lodepng_error_text(error) << endl;
    }

    delete[] byteData;
    return (error == 0);
}