//===========================================
// Course: CIS 054 (100616) C/C++ Programming
// Project: In-Class Assignment 6-2: File In Tree Out (10 Points)
// Names: Olga Sirenko
// Date: 03/03/2020
// Platform:  Linux
// Algorithm:
// Read one char at a time from lab6_2_input.txt
//Write only non-space to terminal
// ==========================================================
// Problems We had working on this assignment (and how I overcame these problems)
// 1. keep the end of line  - by using is blank
// ========================================================== */

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    char c;

    ifstream fin;
    fin.open("lab6_2_input.txt");
    if (fin.fail())
    {
        cout << "Can not open file";
        exit(1);
    }

    while (fin.get(c) && (!fin.eof()))
    {

        if (!isspace(c) || (!isblank(c)))
        {
            cout.put(c);
        }
    }
    fin.close();

    return 0;
}

