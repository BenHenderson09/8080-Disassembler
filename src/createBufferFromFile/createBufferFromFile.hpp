#ifndef CREATE_BUFFER_FROM_FILE_HPP
#define CREATE_BUFFER_FROM_FILE_HPP

#include <string>

uint8_t* createBufferFromFile(const std::string& fileLocation, long fileSizeInBytes);

#endif