project(8080_disassembler)
cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Setup header files
set(HEADER_FILES
    src/getFileSize/getFileSize.hpp
    src/Buffer/Buffer.hpp)

# Setup source files
set(SOURCE_FILES 
    src/8080_disassembler.cpp
    src/getFileSize/getFileSize.cpp
    src/Buffer/Buffer.cpp)

# Create executable
add_executable(8080_disassembler ${SOURCE_FILES} ${HEADER_FILES})