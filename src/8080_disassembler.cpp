#include <string>
#include "createBufferFromFile/createBufferFromFile.hpp"
#include "getFileSize/getFileSize.hpp"

int main(int argc, char** argv){
    std::string fileLocation{argv[1]};
    long fileSizeInBytes{getFileSize(fileLocation)};

    // Dynamically allocated buffer
    uint8_t* buffer{createBufferFromFile(fileLocation, fileSizeInBytes)};

    // Free up memory
    delete[] buffer;
    buffer = nullptr;

    return 0;
}