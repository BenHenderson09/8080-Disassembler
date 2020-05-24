#include <iostream>
#include "../findNumberOfBytesUsedByOpcode/findNumberOfBytesUsedByOpcode.hpp"
#include "../outputDisassembledOpcode/outputDisassembledOpcode.hpp"
#include "../Buffer/Buffer.hpp"
#include "writeDisassembledBufferToConsole.hpp"

void writeDisassembledBufferToConsole(const Buffer& buffer){
    long byteIndex{0};

    while (byteIndex < buffer.getFileSizeInBytes()){
        int bytesUsedByOpcode{findNumberOfBytesUsedByOpcode(buffer[byteIndex])};

        outputDisassembledOpcode(buffer, byteIndex, bytesUsedByOpcode);

        std::cout << '\n';
        byteIndex += bytesUsedByOpcode;
    }
}