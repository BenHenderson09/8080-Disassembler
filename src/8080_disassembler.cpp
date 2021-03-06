#include <iostream>
#include <string>
#include <exception>
#include <FileBuffer/FileBuffer.hpp>
#include "writeDisassembledBufferToConsole/writeDisassembledBufferToConsole.hpp"

int main(int argc, char** argv){
    try {
        const char* fileLocation{argv[1]};
        
        FileBuffer buffer(fileLocation);
        writeDisassembledBufferToConsole(buffer);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';

        return EXIT_FAILURE;
    }

    return 0;
}