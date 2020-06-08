#ifndef OUTPUT_DISASSEMBLED_OPCODE_HPP
#define OUTPUT_DISASSEMBLED_OPCODE_HPP

#include <FileBuffer.hpp>

void outputDisassembledOpcode(const FileBuffer& buffer, long byteIndex, int bytesUsedByOpcode);

#endif