#include <iostream>
#include <string>
#include <exception>
#include "Buffer/Buffer.hpp"
#include "writeDisassembledBufferToConsole/writeDisassembledBufferToConsole.hpp"
#include "checkFileLocationWasProvided/checkFileLocationWasProvided.hpp"

int main(int argc, char** argv){
    try {
        checkFileLocationWasProvided(argv[1]);
        std::string fileLocation{argv[1]};
        
        Buffer buffer(fileLocation);
        writeDisassembledBufferToConsole(buffer);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << "\n";

        return EXIT_FAILURE;
    }

    return 0;
}