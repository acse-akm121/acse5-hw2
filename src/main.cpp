#include <iostream>
#include "image.h"

using std::string;

int main(int argc, char *argv[]) {
    string inFile = "test_image.png";
    string outFile = "test_image_out.png";
    std::cout << "Reading from: " << inFile << std::endl;
    Image img;
    bool err = img.readFromFile(inFile);
    if (!err) {
        std::cerr << "Error reading file, terminating program" << std::endl;
        return 1;
    }
    std::cout << "Successfully read file." << std::endl;
    std::cout << "Trying to write the same image to: " << outFile << std::endl;
    err = img.writeToFile(outFile);
    if (!err) {
        std::cerr << "Error writing file, terminating program" << std::endl;
        return 1;
    }
    std::cout << "Successfully wrote file." << std::endl;
    return 0;
}