#include <string>
#include <sys/stat.h>
#include <stdexcept>
#include "getFileSize.hpp"

long getFileSize(const std::string& fileLocation){
    // Treated as an out-parameter for aggregating file info.
    struct stat fileInfoAggregate;

    // "stat" is a separate function entirely. It gets file info
    // and puts it into the struct.
    int returnCode{stat(fileLocation.c_str(), &fileInfoAggregate)};

    if (returnCode == 0){
        return fileInfoAggregate.st_size; // Size of file (bytes)
    }
    else if (returnCode == -1){
        throw std::runtime_error("Can't determine file size, the file may not exist.");
    }
}