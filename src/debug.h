/* Emulator
 * A simple emulator for a instruction set i made up.
 * Github: https://www.github.com/awesomelewis2007/emulator
 * By: Lewis Evans
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "lib/nice_verbose/nice_verbose.h"
#include "lib/console_colour/colour.h"

#include "main.h"

using namespace std;


/**
 * call_debugger() - Calls the debugger if DEBUG is true
 * @message: The message to display
 * @returns: void
*/
void call_debugger(string message)
{
    if(DEBUG){
        nice_verbose_text::info(message);
    }
}

/**
 * memory_dump() - Dumps the memory in a nice format for debugging
 * @memory: The memory to dump
 * @end: The end of the memory to dump, defaults to 256
 * @returns: void
 * 
 * Dumps the memory in a nice format for debugging. The memory 
 * is dumped in 8 byte chunks.
 * 
 * Example:
 * 00 00 00 00 00 00 00 00
 * 00 00 00 00 00 00 00 00
 * 00 00 00 00 00 00 00 00
 * 00 00 00 00 00 00 00 00
 * 00 00 00 00 00 00 00 00
 * 
 * 
*/
void memory_dump(vector<int> memory, int end = 256)
{
    /* Dumps the memory in a nice format for debugging */
    bool first = true;
    int ln = 0;

    for (int i = 0; i < end; i++)
    {
        if (i % 8 == 0)
        {
            
            /* prevents a new line at the start of the dump */
            if (first)
            {
                first = false;
            }
            else
            {
                cout << endl;
            }
        }
        
        cout << setfill('0') << setw(2) << hex << memory[i] << " ";
    }
    cout << endl;
}


/**
 * reg_dump() - Dumps the registers in a nice format for debugging
 * @a: The value of register A
 * @b: The value of register B
 * @c: The value of register C
 * @d: The value of register D
 * @returns: void
 *
 * Dumps the registers in a nice format for debugging.
*/
void reg_dump(int a,int b,int c, int d)
{
    cout << "A: " << setfill('0') << setw(2) << hex << a << " ";
    cout << "B: " << setfill('0') << setw(2) << hex << b << " ";
    cout << "C: " << setfill('0') << setw(2) << hex << c << " ";
    cout << "D: " << setfill('0') << setw(2) << hex << d << " ";
    cout << endl;
}