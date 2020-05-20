#include <string>
#include "Buffer/Buffer.hpp"

#include <iostream>

int main(int argc, char** argv){
    std::string fileLocation{argv[1]};
    Buffer buffer(fileLocation);

    return 0;
}