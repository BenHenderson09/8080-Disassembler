#include <string>
#include <fstream>
#include "createBufferFromFile.hpp"

uint8_t* createBufferFromFile(const std::string& fileLocation, long fileSizeInBytes){
    std::ifstream file(fileLocation);

    uint8_t* buffer{new uint8_t[fileSizeInBytes]};

    // Copy over each byte to the buffer
    for (int i{0}; i < fileSizeInBytes; i++){
        buffer[i] = file.get();
    }

    return buffer;
}