//===========================================
// Course: CIS 054 (100616) C/C++ Programming
// Project: Lab Assignment 6-1 Removing Blanks
// Names: Olga Sirenko
// Date: 03/08/2020
// Platform:  Linux
// Algorithm:
// 1. Read a file text from file
// 2. remove extra blank spaces from a text
// 3. write an edited version of the same text to another file.
// ==========================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

//void cleanUpFile(ifstream &fin, ofstream &fout);
// Fctn Name:  cleanUpFile
//Purpose: read the text and clean from extra space
//Precondition: read file with text by reference
//Postcondition: write file with edited text

int main()
{

    char inFileName[21];
    const char OUTPUT_FILE[] = "translated.txt";
    ifstream fin;

    cout << "Welcome to Blank Eater!\n";
    cout << "=======================\n";
    cout << "Which file do you want us to clean up?\n";
    cin >> inFileName;
    fin.open(inFileName);
    if (fin.fail()) // checking opening input file
    {
        cout << "Iput file opening failed\n";
        exit(1);
    }

    fout.open(OUTPUT_FILE);
    if (fout.fail()) // checking opening output file
    {
        cout << "Output file opening failed\n";
        exit(1);
    }

    //function to read and edit file
    cleanUpFile(fin, fout);

    fin.close();
    fout.close();
    cout << "Check translated.txt for result!";

    return 0;
}

void cleanUpFile(ifstream &fin, ofstream &fout)
{
    char c;
    int count = 0;
    cout << "Begin editing files.\n";

    while (fin.get(c) && (!fin.eof()))
    {
        if (isalnum(c))
        {
            cout << c;
            fout << c;
            count = 0;
        }
        else if (isspace(c) && count == 0)
        {
            count++;
            cout << c;
            fout << c;
        }
    }
    cout << "\nEnd of editing files\n";
}
