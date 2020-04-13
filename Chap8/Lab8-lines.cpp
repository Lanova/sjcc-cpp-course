//===========================================
// Course: CIS 054 (100616) C/C++ Programming
//Lab Assignment 8-1 Baby Names
// Name: Olga Sirenko
// ID: 0910134
// Date: 03/28/2020
// Platform:  Linux
// ===========================================
// Algoritm:
//    1. Read from the file a list of the 1000 most popular boy and girl names in the United States
//    2. Store data into array
//    3. Aks user to input name to compare
//    4. Compare name with existing list
//    5. Print out result
//    6. Ask if user want to repeat
// Requirement for Formating:
//      Your program will behave exactly as the Solution Demo above.
//      Make use of arrays of c-string to save the boys' and the girls' names
//      Loop to check if user wants to stop the program.
// ===========================================
// Problems: Way to many .. but the most I strugled with storing data from file into array 
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;

void read_file(char numbers[1000][21], char boynames[1000][21], char girlnames[1000][21]);
//Purpose: read ifstream from file and store date in numbers, biynames and girlnames accordintly
//Precondition: file consiste from range, boyname, girlname
//Postcondition: data stored in tree arrays numbers, biynames and girlsnames

void search(char name[21], const char boynames[1000][21], const char girlnames[1000][21]);
//Purpose: comapere user inputed name to existing names in boynames array and girlnames array
//Precondition: user input in the same format as names stored
//Postcondition: printed name and range among boys and girls
//              if name is not found printed the message accordintly

int main()
{

    char numbers[1000][21];//used only to store ranges
    char boynames[1000][21];
    char girlnames[1000][21];
    char name[21];
    char user_input = 'n';

    read_file(numbers, boynames, girlnames);//stores date from file into arrays

    cout << "Welcome to Baby Name Ranking DB!\n";
    cout << "================================\n";
    do
    {
        cout << "Which name do you want to search on our DB?\n";
        cin >> name;//user name input
        search(name, boynames, girlnames);//search if this name exist in boy and girl lists
        cout << "Search again? (y/n)\n";
        cin >> user_input;

    } while (user_input == 'y' || user_input == 'Y');

    return 0;
}

void read_file(char numbers[1000][21], char boynames[1000][21], char girlnames[1000][21])
{
    int i = 0;
    ifstream fin;
    fin.open("babynames2012.txt");
    if (fin.fail())
    {
        cout << "Cannot open file";
        exit(1);
    }

    while (fin >> numbers[i] >> boynames[i] >> girlnames[i])
    {
        i++;
    }
}

void search(char name[21], const char boynames[1000][21], const char girlnames[1000][21])
{
    bool flagB, flagG = false;
    for (int i = 0; i <= 1000; i++)
    {
        if (strcmp(name, boynames[i]) == 0)
        {
            cout << name << " is ranked " << i + 1 << " in popularity among boys." << endl;
            flagB = true;
        }
        if (strcmp(name, girlnames[i]) == 0)
        {
            cout << name << " is ranked " << i + 1 << " in popularity among girls." << endl;
            flagG = true;
        }
    }
    if (!flagB)
        cout << name << " is not ranked among the top 1000 boys names." << endl;
    if (!flagG)
        cout << name << " is not ranked among the top 1000 girl names." << endl;
}
