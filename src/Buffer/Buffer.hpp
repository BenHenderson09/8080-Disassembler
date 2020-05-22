#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <string>

class Buffer {
    public:        
        Buffer(const std::string& fileLocation);
        ~Buffer();

        uint8_t operator[](long byteIndex) const;

        long getFileSizeInBytes() const;

    private:
        uint8_t* heapBasedBuffer;
        long fileSizeInBytes;
};

#endif