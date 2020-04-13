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
// Problems:
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void read_file();
//Purpose: formant first letter of each word to Uppercase the rest to lower
//Precondition: string consist from alphabetical values
//Assumption: user may inputed alphabetical value in different cases
//Postcondition: each word is Capitalized

void print_2d_arr(const char babynames[1000][2][21]);

int main()
{
    char name[21];
    char user_input = 'n';

    read_file();
    cout << "Welcome to Baby Name Ranking DB!\n";
    cout << "================================\n";
    do
    {

        cout << "Which name do you want to search on our DB?\n";
        cin >> name;
        cout << "Your name is " << name << endl;
        cout << "Search again? (y/n)\n";
        cin >> user_input;

    } while (user_input == 'y' || user_input == 'Y');

    return 0;
}

// void read_file(ifstream &fin)
// {
//     const int ARRAY_SIZE = 50;
//     int arr[ARRAY_SIZE];
//     int size = 0;
//     int x;
//     while (size <= ARRAY_SIZE && fin >> x && !fin.eof())
//     //checking if the size smaller than array size - in case in file > 50
//     // && if there is at least one element && if it's not end of line
//     {
//         arr[size++] = x;
//     }
// }

void read_file()
{char array [][COLS], int rows, int scores []
   
    ifstream fin;
    fin.open("babynames2012.txt");
    if (fin.fail())
    {
        cout << "Can not open file";
        exit(1);
    }

    
for (int r = 0; r < rows; r++)
{
    int c = 0;
    char ch;
    // keep reading until we hit a space
    ch = fin.get();
    while (ch != ' ')
    {
        array[r][c] = ch;
        c++;
        ch = fin.get();
    }
    // now read the score
    fin >> scores[r];
    // now read until we hit the trailing newline
    ch = fin.get();
    while (ch != '\n' && ch != EOF)
    {
        ch = fin.get();

    }
}

        for (int count = 0; count < rows; count++)
        {
            for(int i = 0; i < COLS; i++)
            {
                cout << array[count][i];
                for (int count2 = 0; count2 < rows; count2++)
                    cout << scores[count2];
            }
        }
    fin.close();

   print_2d_arr(babynames);
}

void print_2d_arr(const char babynames[1000][2][21])
{

    int width = 2, height = 1000;

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
            cout << babynames[i][j] << ' ';
        cout << endl;
    }
}


 // printing
//   for (int i = 0; i <= 1000; i++)
//         cout << numbers[i] << " " << boynames[i] << " " << girlnames[i] << "\n";