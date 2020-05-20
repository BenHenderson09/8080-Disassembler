#include <string>
#include <fstream>
#include "Buffer.hpp"
#include "../getFileSize/getFileSize.hpp"

Buffer::Buffer(const std::string& fileLocation){
    std::ifstream file(fileLocation);
    fileSizeInBytes = getFileSize(fileLocation);

    // Dynamically allocated buffer
    uint8_t* heapBasedBuffer{new uint8_t[fileSizeInBytes]};

    // Copy over each byte to the buffer
    for (int i{0}; i < fileSizeInBytes; i++){
        heapBasedBuffer[i] = file.get();
    }

    this->heapBasedBuffer = heapBasedBuffer;
}

Buffer::~Buffer(){
    // Free up memory
    delete[] heapBasedBuffer;
}

uint8_t Buffer::operator[](long byteIndex){
    return heapBasedBuffer[byteIndex];
}

long Buffer::getFileSizeInBytes(){
    return fileSizeInBytes;
}
