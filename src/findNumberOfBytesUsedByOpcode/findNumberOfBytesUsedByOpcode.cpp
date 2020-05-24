#include <map>
#include <string>
#include "findNumberOfBytesUsedByOpcode.hpp"
#include "../../config/OpcodeConfig.hpp"

namespace {
    bool isOpcodePresentInMap(uint8_t opcode, const std::map<uint8_t, std::string>& map){
        return map.find(opcode) != map.end();
    }
}

int findNumberOfBytesUsedByOpcode(uint8_t opcode){
    bool usesOneByte{isOpcodePresentInMap(opcode, OpcodeConfig::oneByteOpcodes)};
    bool usesTwoBytes{isOpcodePresentInMap(opcode, OpcodeConfig::twoByteOpcodes)};
    bool usesThreeBytes{isOpcodePresentInMap(opcode, OpcodeConfig::threeByteOpcodes)};

    if (usesOneByte) return 1;
    else if (usesTwoBytes) return 2;
    else if (usesThreeBytes) return 3;
}