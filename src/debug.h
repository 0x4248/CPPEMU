/* Emulator
 * A simple emulator for a instruction set i made up.
 * Github: https://www.github.com/awesomelewis2007/emulator
 * By: awesomelewis2007
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "lib/nice_verbose/nice_verbose.h"
#include "lib/console_colour/colour.h"

#include "main.h"

using namespace std;

void call_debugger(string message)
{
    if(DEBUG){
        nice_verbose_text::info(message);
    }
}

void memory_dump(vector<int> memory, int end = 256)
{
    //Dumps the memory in a nice format for debugging
    bool first = true;
    int ln = 0;

    for (int i = 0; i < end; i++)
    {
        if (i % 8 == 0)
        {
            
            //prevents a new line at the start of the dump
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

void reg_dump(int a,int b,int c, int d)
{
    cout << "A: " << setfill('0') << setw(2) << hex << a << " ";
    cout << "B: " << setfill('0') << setw(2) << hex << b << " ";
    cout << "C: " << setfill('0') << setw(2) << hex << c << " ";
    cout << "D: " << setfill('0') << setw(2) << hex << d << " ";
    cout << endl;
}