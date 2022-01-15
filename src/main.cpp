#include <iostream>
#include "image.h"
#include "filter.h"

using std::string;

int main(int argc, char *argv[]) {
    string inFile = "data/test_image.png";
    string outFile = "data/test_image_out.png";
    std::cout << "Reading from: " << inFile << std::endl;
    Image img;
    bool err = img.readFromFile(inFile);
    if (!err) {
        std::cerr << "Error reading file, terminating program" << std::endl;
        return 1;
    }
    std::cout << "Successfully read file." << std::endl;
    ImageFilter filter;
    unsigned centX = 2 * img.width() / 10;
    unsigned centY = 4 * img.height() / 5;
    Image spotlitImg = filter.spotlight(img, centX, centY);
    std::cout << "Trying to write the spotlit image to: " << outFile << std::endl;
    err = spotlitImg.writeToFile(outFile);
    if (!err) {
        std::cerr << "Error writing file, terminating program" << std::endl;
        return 1;
    }
    std::cout << "Successfully wrote file." << std::endl;
    return 0;
}