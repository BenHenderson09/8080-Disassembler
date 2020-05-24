#include <stdexcept>
#include "checkFileLocationWasProvided.hpp"

void checkFileLocationWasProvided(const char* fileLocation){
    if (!fileLocation) throw std::runtime_error("File location must be provided.");
}