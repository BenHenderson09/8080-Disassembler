# 8080-Disassembler
Disassembles a binary executable designed for the Intel 8080 microprocessor back into assembly language.

## Program Details
 - Made with C++
 - Built with CMake
 - No third party libraries
 
 ## Usage
 Usage is fairly simple, following the standard method with CMake. Run as root.
 1. `git clone https://github.com/BenHenderson09/8080-Disassembler`
 2. `mkdir -p 8080-Disassembler/build && cd 8080-Disassembler/build`
 3. `cmake .. && make`
 
 Then, to disassemble a file: `./8080_disassembler <your file location>`
 
 ## Example
 Command: `./8080_disassembler space_invaders.h`
 
Output:
```assembly
0x00000 | 0x00: NOP       
0x00001 | 0x00: NOP       
0x00002 | 0x00: NOP       
0x00003 | 0xc3: JMP       0x18d4
0x00006 | 0x00: NOP       
0x00007 | 0x00: NOP       
0x00008 | 0xf5: PUSH PSW  
0x00009 | 0xc5: PUSH B    
0x0000a | 0xd5: PUSH D    
0x0000b | 0xe5: PUSH H    
0x0000c | 0xc3: JMP       0x008c
...
 ```
The output will have the index of the instruction displayed in the leftmost column,
the hexadecimal opcode in the next column, the assembly mnemonic in the following column 
and finally the hexadecimal operands displayed in the rightmost column.
