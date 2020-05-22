#include <iostream>
#include <iomanip>
#include <map>
#include "../Buffer/Buffer.hpp"
#include "../../config/OpcodeConfig.hpp"

namespace {
    void disassembleOpcodeAtByteIndex(long& byteIndex, const Buffer& buffer);

    void setConsoleToOutputHexNumbers();
    void setConsoleToOutputMnemonic();

    void outputByteIndexToConsole(long byteIndex);
    void outputOpcodeToConsole(uint8_t opcode);
    void outputMnemonic(uint8_t opcode, int bytesUsedByMnemonic);
    void outputMnemonicOperands(long byteIndex, int bytesUsedByMnemonic, const Buffer& buffer);

    int findNumberOfBytesUsedByOpcode(uint8_t opcode);
    bool isOpcodePresentInMap(uint8_t opcode, const std::map<uint8_t, std::string>& map);

    void disassembleOpcodeAtByteIndex(long& byteIndex, const Buffer& buffer){
        uint8_t opcode{buffer[byteIndex]};
        int bytesUsedByOpcode{findNumberOfBytesUsedByOpcode(opcode)};

        outputByteIndexToConsole(byteIndex);
        outputOpcodeToConsole(opcode);

        outputMnemonic(opcode, bytesUsedByOpcode);
        outputMnemonicOperands(byteIndex, bytesUsedByOpcode, buffer);

        byteIndex += bytesUsedByOpcode;
        std::cout << '\n';
    }

    void setConsoleToOutputHexNumbers(){
        // Set number format to hexadecimal
        std::cout << std::hex;

        // Pad any numbers which don't use all the reserved digits with zero
        std::cout << std::setfill('0') << std::right;
    }

    void setConsoleToOutputMnemonic(){
        // Fill mnemonic with spaces if they don't use all reserved characters
        // Also align them to the left for readability
        std::cout << std::setfill(' ') << std::left;
    }

    void outputByteIndexToConsole(long byteIndex){
        setConsoleToOutputHexNumbers();

        // Reserve 5 digits to display byte index
        std::cout << "0x" << std::setw(5) << byteIndex << " | ";
    }

    void outputOpcodeToConsole(uint8_t opcode){
        setConsoleToOutputHexNumbers();

        // Reserve 2 digits to display the hexadecimal opcode
        std::cout << "0x" << std::setw(2) << (int)opcode <<  ": ";
    }

    void outputMnemonic(uint8_t opcode, int bytesUsedByMnemonic){
        setConsoleToOutputMnemonic();

        switch (bytesUsedByMnemonic){
            case 1:
                std::cout << std::setw(10) << OpcodeConfig::oneByteOpcodes.at(opcode);
                break;

            case 2:
                std::cout << std::setw(10) << OpcodeConfig::twoByteOpcodes.at(opcode);
                break;

            case 3:
                std::cout << std::setw(10) << OpcodeConfig::threeByteOpcodes.at(opcode);
                break;
        }
    }

    void outputMnemonicOperands(long byteIndex, int bytesUsedByMnemonic, const Buffer& buffer){
        setConsoleToOutputHexNumbers();

        if (bytesUsedByMnemonic == 2){
            uint8_t operand{buffer[byteIndex+1]};
            std::cout << "0x" << std::setw(4) << (int)operand;
        }
        else if (bytesUsedByMnemonic == 3){
            uint8_t firstOperand{buffer[byteIndex+1]};
            uint8_t secondOperand{buffer[byteIndex+2]};

            // In assembly (for the 8080), two bytes provided as operands will specify a 16-bit address.
            // The first byte (firstOperand) is the lower-order (less significant) portion and the second
            // byte is the higher-order (more significant) portion.
            std::cout << "0x" << std::setw(2) << (int)secondOperand;
            std::cout << std::setw(2) << (int)firstOperand;
        }
    }

    int findNumberOfBytesUsedByOpcode(uint8_t opcode){
        bool usesOneByte{isOpcodePresentInMap(opcode, OpcodeConfig::oneByteOpcodes)};
        bool usesTwoBytes{isOpcodePresentInMap(opcode, OpcodeConfig::twoByteOpcodes)};
        bool usesThreeBytes{isOpcodePresentInMap(opcode, OpcodeConfig::threeByteOpcodes)};
    
        if (usesOneByte) return 1;
        if (usesTwoBytes) return 2;
        if (usesThreeBytes) return 3;
    }

    bool isOpcodePresentInMap(uint8_t opcode, const std::map<uint8_t, std::string>& map){
        return map.find(opcode) != map.end();
    }
}

void writeDisassembledBufferToConsole(const Buffer& buffer){
    long byteIndex{0};

    while (byteIndex < buffer.getFileSizeInBytes()){
        disassembleOpcodeAtByteIndex(byteIndex, buffer);
    }
}