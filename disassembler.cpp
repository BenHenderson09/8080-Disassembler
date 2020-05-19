#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <sys/stat.h>

long getFileSize(const std::string& fileLocation){
    // Treated as an out-parameter for aggregating file info.
    struct stat fileInfoAggregate;

    // "stat" is a separate function entirely. It gets file info
    // and puts it into the struct.
    int returnCode = stat(fileLocation.c_str(), &fileInfoAggregate);

    if (returnCode == 0){
        return fileInfoAggregate.st_size; // Size of file (bytes)
    }
    else if (returnCode == -1){
        throw std::runtime_error("Can't determine file size");
    }
}

void readFileToBuffer(const std::string& fileLocation, long fileSizeInBytes, uint8_t* buffer){
    std::ifstream file(fileLocation);

    for (int i = 0; i < fileSizeInBytes; i++){
        buffer[i] = file.get();
    }
}

int main(int argc, char** argv){
    std::string fileLocation{argv[1]};
    long fileSizeInBytes{getFileSize(fileLocation)};

    uint8_t buffer[fileSizeInBytes];
    readFileToBuffer(fileLocation, fileSizeInBytes, buffer);
    

    // Printing hex
    for (int i = 0; i < fileSizeInBytes; i++){
        std::cout << std::hex << (int)buffer[i] << std::dec;
    }

    std::cout << '\n';

    return 0;
}