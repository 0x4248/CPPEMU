# CPPEMU
A simple emulator for a instruction set i made up.

This is a simple emulator for a instruction set i made up. It is not meant to be a real emulator, but rather a fun project I made.

I have also made a compiler for CPUEMU which compiles a readable assembly like code to CPPEMU bytes. [Check it out here](https://github.com/lewisevans2007/CPPEMU-Compiler)

## How to use 
To use then emulator you need the emulator and a file with the instructions. The emulator takes the file as an argument. The file should be a text file with the instructions in it. The instructions should be separated by a newline. The emulator will then execute the instructions in the order they are in the file.

```
./emulator instructions.txt
```

## Instructions
There are many instructions that the emulator can execute. The instructions are as follows:
```
0x00 Blank instruction
0x01 Select memory location with the next hex number
0x02 Put the next hex number into the selected memory location
0x03 Add the next hex number to the selected memory location and store the result in the selected memory location
0x04 Subtract the next hex number from the selected memory location and store the result in the selected memory location
0x05 Multiply the selected memory location by the next hex number and store the result in the selected memory location
0x06 Divide the selected memory location by the next hex number and store the result in the selected memory location
```
```
0x1A Set register A to the next hex number
0x1B Set register B to the next hex number
0x1C Set register C to the next hex number
0x1D Set register D to the next hex number
```
```
0x2A Set register A to the selected memory location
0x2B Set register B to the selected memory location
0x2C Set register C to the selected memory location
0x2D Set register D to the selected memory location
```
```
0x3A Set the selected memory location to the value of register A
0x3B Set the selected memory location to the value of register B
0x3C Set the selected memory location to the value of register C
0x3D Set the selected memory location to the value of register D
```
```
0x4A Add the value of register A to the selected memory location and store the result in the selected memory location
0x4B Add the value of register B to the selected memory location and store the result in the selected memory location
0x4C Add the value of register C to the selected memory location and store the result in the selected memory location
0x4D Add the value of register D to the selected memory location and store the result in the selected memory location
```
```
0x5A Subtract the value of register A from the selected memory location and store the result in the selected memory location
0x5B Subtract the value of register B from the selected memory location and store the result in the selected memory location
0x5C Subtract the value of register C from the selected memory location and store the result in the selected memory location
0x5D Subtract the value of register D from the selected memory location and store the result in the selected memory location
```
```
0x6A Multiply the selected memory location by the value of register A and store the result in the selected memory location
0x6B Multiply the selected memory location by the value of register B and store the result in the selected memory location
0x6C Multiply the selected memory location by the value of register C and store the result in the selected memory location
0x6D Multiply the selected memory location by the value of register D and store the result in the selected memory location
```
```
0x7A Divide the selected memory location by the value of register A and store the result in the selected memory location
0x7B Divide the selected memory location by the value of register B and store the result in the selected memory location
0x7C Divide the selected memory location by the value of register C and store the result in the selected memory location
0x7D Divide the selected memory location by the value of register D and store the result in the selected memory location
```
```
0xAA Stop the program
0xAB Print the value of the selected memory location
0xBA Print the value of register A
0xBB Print the value of register B
0xBC Print the value of register C
0xBD Print the value of register D
```

## License

This project is licensed under the GPL-3.0 License - see the [LICENCE](LICENCE) file for details