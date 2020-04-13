//===========================================
// Course: CIS 054 (100616) C/C++ Programming
//Bonus In-Class Assignment 8-2 Formatting Names (40 points)
// Name: Olga Sirenko
// ID: 0910134
// Date: 03/25/2020
// Platform:  Linux
// ===========================================
/**
Write a program that reads a person’s name in the following format:
      first name, then middle name or initial, and then last name. 

The program then outputs the name in the following format:
      Last_Name, First_Name Middle_Initial.

Your program will:

Add a period after the middle initial
Allow for users to give no middle name or middle initial
Capitalized the name properly
 */
#include <iostream>
#include <string>
#include <bits/stdc++.h> 


using namespace std;

void formatting(string fullname);
// Name:
//Purpose: Connect to file stream
//        if the file cannot be opened, the program will exit
//        read file stream, populate 'the array arr with integers from fin
//Assumption: user's file has less than 50 integers
//Postcondition: fin has been successfully connected to the file & store integers into array
// Calls: creat_hashmap()

int main()
{
    string fname, mname,lname2;
    string lname;
    string trash;

    int count;

    char user_input = 'n';

    cout << "Welcome to The Awesomest Name Reformer!\n";
    cout << "=======================================\n";

    do{
        cout << "What is your name? \n";
        getline(cin, fname, ' ');
        getline(cin, mname)>> lname;
      
        cout << lname << ", " << trash<< endl; 
        cout << "Do you want to enter another name? (y/n)\n";
        cin >> user_input;
    } while (user_input == 'y' || user_input == 'Y');

    return 0;
}

void formatting(string name){

    int i=0;

}