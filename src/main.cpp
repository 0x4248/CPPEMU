// Emulator
// A simple emulator for a instruction set i made up.
// Github: https://www.github.com/awesomelewis2007/emulator
// By: awesomelewis2007

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>
#include <utility>
#include <functional>

#include "lib/nice_verbose/nice_verbose.h"
#include "lib/console_colour/colour.h"

#include "debug.h"
#include "main.h"

using namespace std;

int main(int argc, char *argv[])
{
    if(argv[1] == string("--version") || argv[1] == string("-v"))
    {
        cout << "Emulator version " << VERSION << endl;
        return 0;
    }
    if (argv[1] == string("--help") || argv[1] == string("-h"))
    {
        cout << "Usage: emulator [options] [program file]" << endl;
        cout << "Options:" << endl;
        cout << "  -h, --help     Show this help message" << endl;
        cout << "  -v, --version  Show the version of the emulator" << endl;
    }
    if (argc < 2)
    {
        cout << "Please provide a program file" << endl;
        return 1;
    }
    nice_verbose_text::ok("Starting emulator");
    ifstream file(argv[1]);
    nice_verbose_text::ok("Loading program file");
    string line;
    vector<string> instructions;
    nice_verbose_text::ok("Initializing memory");
    vector<int> memory(256, 0);
    nice_verbose_text::ok("Initializing registers");
    int reg_a = 0;
    int reg_b = 0;
    int reg_c = 0;
    int reg_d = 0;

    int location = 0;
    while(getline(file, line))
    {
        for(int i = 0; i < line.length(); i += 2)
        {
            instructions.push_back(line.substr(i, 2));
        }
    }
    for (int i = 0; i < instructions.size(); i++)
    {
        call_debugger(to_string(i)   + " -> " + instructions[i]);
        if (instructions[i] == "00")
        {
        }
        else if (instructions[i] == "01")
        {
            int location = stoi(instructions[i + 1], nullptr, 16);
            call_debugger("SELECT " + to_string(location));
            i++;
        }
        else if (instructions[i] == "02")
        {
            int number = stoi(instructions[i + 1], nullptr, 16);
            call_debugger("PUT " + to_string(number) + " -> " + to_string(location));
            memory[location] = number;
            i++;
        }
        else if (instructions[i] == "03")
        {
            int number = stoi(instructions[i + 1], nullptr, 16);
            call_debugger("ADD " + to_string(number) + " -> " + to_string(location));
            memory[location] = memory[location] + number;
            i++;
        }
        else if (instructions[i] == "04")
        {
            int number = stoi(instructions[i + 1], nullptr, 16);
            call_debugger("MIN " + to_string(number) + " -> " + to_string(location));
            memory[location] = memory[location] - number;
            i++;
        }
        else if (instructions[i] == "05")
        {
            int number = stoi(instructions[i + 1], nullptr, 16);
            call_debugger("MUL " + to_string(number) + " -> " + to_string(location));
            memory[location] = memory[location] * number;
            i++;
        }
        else if (instructions[i] == "06")
        {
            int number = stoi(instructions[i + 1], nullptr, 16);
            call_debugger("DIV " + to_string(number) + " -> " + to_string(location));
            memory[location] = memory[location] / number;
            i++;
        }
        else if (instructions[i] == "1A")
        {
            reg_a = stoi(instructions[i + 1], nullptr, 16);
            call_debugger("SET A " + to_string(reg_a) + " -> " + to_string(location));
            i++;
        }
        else if (instructions[i] == "1B")
        {
            reg_b = stoi(instructions[i + 1], nullptr, 16);
            call_debugger("SET B " + to_string(reg_b) + " -> " + to_string(location));
            i++;
        }
        else if (instructions[i] == "1C")
        {
            reg_c = stoi(instructions[i + 1], nullptr, 16);
            call_debugger("SET C " + to_string(reg_c) + " -> " + to_string(location));
            i++;
        }
        else if (instructions[i] == "1D")
        {
            reg_d = stoi(instructions[i + 1], nullptr, 16);
            call_debugger("SET D " + to_string(reg_d) + " -> " + to_string(location));
            i++;
        }
        else if (instructions[i] == "2A")
        {
            reg_a = memory[location];
            call_debugger("GET A " + to_string(reg_a) + " <- " + to_string(location));
        }
        else if (instructions[i] == "2B")
        {
            reg_b = memory[location];
            call_debugger("GET B " + to_string(reg_b) + " <- " + to_string(location));
        }
        else if (instructions[i] == "2C")
        {
            reg_c = memory[location];
            call_debugger("GET C " + to_string(reg_c) + " <- " + to_string(location));
        }
        else if (instructions[i] == "2D")
        {
            reg_d = memory[location];
            call_debugger("GET D " + to_string(reg_d) + " <- " + to_string(location));
        }
        else if (instructions[i] == "3A")
        {
            memory[location] = reg_a;
            call_debugger("GET A " + to_string(reg_a) + " -> " + to_string(location));
        }
        else if (instructions[i] == "3B")
        {
            memory[location] = reg_b;
            call_debugger("GET B " + to_string(reg_b) + " -> " + to_string(location));
        }
        else if (instructions[i] == "3C")
        {
            memory[location] = reg_c;
            call_debugger("GET C " + to_string(reg_c) + " -> " + to_string(location));
        }
        else if (instructions[i] == "3D")
        {
            memory[location] = reg_d;
            call_debugger("GET D " + to_string(reg_d) + " -> " + to_string(location));
        }
        else if (instructions[i] == "4A")
        {
            memory[location] = memory[location] + reg_a;
            call_debugger("ADD A " + to_string(reg_a) + " -> " + to_string(location));
        }
        else if (instructions[i] == "4B")
        {
            memory[location] = memory[location] + reg_b;
            call_debugger("ADD B " + to_string(reg_b) + " -> " + to_string(location));
        }
        else if (instructions[i] == "4C")
        {
            memory[location] = memory[location] + reg_c;
            call_debugger("ADD C " + to_string(reg_c) + " -> " + to_string(location));
        }
        else if (instructions[i] == "4D")
        {
            memory[location] = memory[location] + reg_d;
            call_debugger("ADD D " + to_string(reg_d) + " -> " + to_string(location));
        }
        else if (instructions[i] == "5A")
        {
            memory[location] = memory[location] - reg_a;
            call_debugger("MIN A " + to_string(reg_a) + " -> " + to_string(location));
        }
        else if (instructions[i] == "5B")
        {
            memory[location] = memory[location] - reg_b;
            call_debugger("MIN B " + to_string(reg_b) + " -> " + to_string(location));
        }
        else if (instructions[i] == "5C")
        {
            memory[location] = memory[location] - reg_c;
            call_debugger("MIN C " + to_string(reg_c) + " -> " + to_string(location));
        }
        else if (instructions[i] == "5D")
        {
            memory[location] = memory[location] - reg_d;
            call_debugger("MIN D " + to_string(reg_d) + " -> " + to_string(location));
        }
        else if (instructions[i] == "6A")
        {
            memory[location] = memory[location] * reg_a;
            call_debugger("MUL A " + to_string(reg_a) + " -> " + to_string(location));
        }
        else if (instructions[i] == "6B")
        {
            memory[location] = memory[location] * reg_b;
            call_debugger("MUL B " + to_string(reg_b) + " -> " + to_string(location));
        }
        else if (instructions[i] == "6C")
        {
            memory[location] = memory[location] * reg_c;
            call_debugger("MUL C " + to_string(reg_c) + " -> " + to_string(location));
        }
        else if (instructions[i] == "6D")
        {
            memory[location] = memory[location] * reg_d;
            call_debugger("MUL D " + to_string(reg_d) + " -> " + to_string(location));
        }
        else if (instructions[i] == "7A")
        {
            memory[location] = memory[location] / reg_a;
            call_debugger("DIV A " + to_string(reg_a) + " -> " + to_string(location));
        }
        else if (instructions[i] == "7B")
        {
            memory[location] = memory[location] / reg_b;
            call_debugger("DIV B " + to_string(reg_b) + " -> " + to_string(location));
        }
        else if (instructions[i] == "7C")
        {
            memory[location] = memory[location] / reg_c;
            call_debugger("DIV C " + to_string(reg_c) + " -> " + to_string(location));
        }
        else if (instructions[i] == "7D")
        {
            memory[location] = memory[location] / reg_d;
            call_debugger("DIV D " + to_string(reg_d) + " -> " + to_string(location));
        }

        else if (instructions[i] == "AA")
        {
            call_debugger("STP");
            nice_verbose_text::ok("CPU Stopped end of program");
            return 0;
        }
        else if (instructions[i] == "AB")
        {
            call_debugger("PRN " + to_string(location));
            cout << memory[location] << endl;
        }
        else if (instructions[i] == "BA")
        {
            call_debugger("PRN A");
            cout << reg_a << endl;
        }
        else if (instructions[i] == "BA")
        {
            call_debugger("PRN B");
            cout << reg_b << endl; 
        }
        else if (instructions[i] == "BC")
        {
            call_debugger("PRN C");
            cout << reg_c << endl;
        }
        else if (instructions[i] == "BD")
        {
            call_debugger("PRN D");
            cout << reg_d << endl;
        }
        if(TRACE){
            cout << "======[REGISTERS]======" << endl;
            reg_dump(reg_a, reg_b, reg_c, reg_d);
            cout << "========[MEMORY]=======" << endl;
            memory_dump(memory);
        }
    }
    nice_verbose_text::ok("Ran out of instructions to execute. CPU Stopped end of program");
    return 0;
}
