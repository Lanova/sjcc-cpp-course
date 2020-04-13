//===========================================
// Course: CIS 054 (100616) C/C++ Programming
//Bonus In-Class Assignment 8-2 Formatting Names (40 points)
// Name: Olga Sirenko
// ID: 0910134
// Date: 03/25/2020
// Platform:  Linux
// ===========================================
// Algoritm:
//      1.Program reads  user input name in the following format:
//      first name, then middle name or initial, and then last name.
//      2. Formating reseived input
//      3. Print in the needed format the result

//Expected Output: Last_Name, First_Name Middle_Initial.
//                Ex. Sirenko, Olga S.
// Requirement for Formating:
//      Add a period after the middle initial
//      Allow for users to give no middle name or middle initial;
//      Capitalized the name properly

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void formator(string &full_name);
//Purpose: formant first letter of each word to Uppercase the rest to lower
//Precondition: string consist from alphabetical values
//Assumption: user may inputed alphabetical value in different cases
//Postcondition: each word is Capitalized

void str_to_vector(string str, char delim, vector<string> &str_arr);
//Purpose: split string by space and store into vector
//Precondition: string inputed by user, delimenetor exist in str
//Assumption: user input name consistence from 2-3 words
//Postcondition: each word storred into array/vector

void assigner(string &fname, string &mname, string &lname, vector<string> &str_arr);
//Purpose: assigns value from vector to first, last and middle name accordintly
//Precondition: vectror stores value
//Assumption: vector consist from 2-3 words
//Postcondition: each part of name has right value from vectror

int main()
{

    char user_input = 'n';

    cout << "Welcome to The Awesomest Name Reformer!\n";
    cout << "=======================================\n";
    do
    {
        string full_name;
        string fname, mname, lname;
        vector<string> str_arr;

        cout << "What is your name? \n";
        cin >> ws; //clean the extra white space for the repeated input
        getline(cin, full_name);
        formator(full_name);                    //Capitalizing the name
        str_to_vector(full_name, ' ', str_arr); // convert string to vector
        assigner(fname, mname, lname, str_arr); // split vector and assign value to first, last and middle name accordintly
        cout << "Your name reformatted:" << endl;
        cout << lname << ", " << fname << " ";
        if (!mname.empty()) // print inicial only if it exist
        {
            cout << mname << ".";
        }
        cout << endl;

        cout << "Do you want to enter another name? (y/n)\n";
        cin >> user_input;

    } while (user_input == 'y' || user_input == 'Y');

    return 0;
}
void formator(string &full_name)
{
    int size = full_name.size();
    full_name[0] = toupper(full_name[0]);

    for (int i = 1; i < size; i++)
    {
        if (full_name[i - 1] == ' ')
            full_name[i] = toupper(full_name[i]);
        else
            full_name[i] = tolower(full_name[i]);
    }
}
void str_to_vector(string str, char delim, vector<string> &str_arr)
{
    // construct a stream from the string
    stringstream ss(str);
    string s;
    while (getline(ss, s, delim))
    {
        str_arr.push_back(s);
    }
}

void assigner(string &fname, string &mname, string &lname, vector<string> &str_arr)
{
    if (str_arr.size() == 2)
    {
        fname = str_arr[0];
        lname = str_arr[1];
    }
    else if (str_arr.size() == 3)
    {
        fname = str_arr[0];
        mname = str_arr[1][0];
        lname = str_arr[2];
    }
    else
    {
        cout << "The name is in incorect format" << endl;
    }
}
