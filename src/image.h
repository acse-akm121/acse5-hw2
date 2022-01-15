#ifndef AKM_IMAGE_H
#define AKM_IMAGE_H


#include <string>
#include <vector>
#include "pixel.h"

using std::string;

/*
Image class for PNG images.
*/
class Image {
    public:
        // Constructors / Destructor
        Image();
        Image(unsigned int width, unsigned int height);
        Image(Image const & other);
        ~Image();

        // File I/O
        bool readFromFile(string const & filename);
        bool writeToFile(string const & filename);

        /*
        Pixel access operator - Get a pointer to a pixel, allows 
        the pixel values to be changed.
        */
        Pixel * getPixel(unsigned int x, unsigned int y);

        // Accessors
        unsigned int width() const;
        unsigned int height() const;

    private:
        unsigned int width_;
        unsigned int height_;
        Pixel *imageData_;
        
        /*
        Copies the contents of other to self.
        */
        void _copy(Image const & other);

};

#endif