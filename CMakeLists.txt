project(8080_disassembler)
cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Setup header files
set(HEADER_FILES
    src/writeDisassembledBufferToConsole/writeDisassembledBufferToConsole.hpp
    src/findNumberOfBytesUsedByOpcode/findNumberOfBytesUsedByOpcode.hpp
    src/outputDisassembledOpcode/outputDisassembledOpcode.hpp
    config/OpcodeConfig.hpp)

# Setup source files
set(SOURCE_FILES 
    src/8080_disassembler.cpp
    src/writeDisassembledBufferToConsole/writeDisassembledBufferToConsole.cpp
    src/findNumberOfBytesUsedByOpcode/findNumberOfBytesUsedByOpcode.cpp
    src/outputDisassembledOpcode/outputDisassembledOpcode.cpp)

# Create executable
add_executable(8080_disassembler ${SOURCE_FILES} ${HEADER_FILES})

# Setup libraries
include_directories(deps/FileBuffer/include)
find_library(FILE_BUFFER FileBuffer deps/FileBuffer/lib)

target_link_libraries(8080_disassembler LINK_PUBLIC ${FILE_BUFFER})