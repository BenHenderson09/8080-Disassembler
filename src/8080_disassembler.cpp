#include <string>
#include "Buffer/Buffer.hpp"
#include "writeDisassembledBufferToConsole/writeDisassembledBufferToConsole.hpp"
#include "getFileSize/getFileSize.hpp"

int main(int argc, char** argv){
    std::string fileLocation{argv[1]};
    Buffer buffer(fileLocation);

    writeDisassembledBufferToConsole(buffer);

    return 0;
}