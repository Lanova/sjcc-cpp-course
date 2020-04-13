//===========================================
// Course: CIS 054 (100616) C/C++ Programming
// Lab Assignment 10-1 Day of Week Program
// Name: Olga Sirenko
// ID: 0910134
// Date: 04/12/2020
// Platform:  Linux
// ===========================================
// Algoritm:
//      1. Accepts a 3-letter input from the user as the week of day
//            1.1. an input function that reads the day as the first three letters, accepts an input stream as parameter
//      2.Outputs the current day number, following by the next 6 days'
//          2.1 an output function that outputs the day as an integer, accepts an output stream as parameter
//          2.2. a member function that returns the next day as a value of type DayOfWeek.
// Requirements:
//      1. Follow the ADT (Abstract Data Type) guideline to implement the required class
//      2. Comment well in your program and any functions you use
// Problems:
//      not sure if we need as well set(int), set(char) or only constractors that setting them
//      didn't know how to test istream with user input

#include <iostream>
#include <istream>

using namespace std;

class DayOfWeek
{
public:
    DayOfWeek(char first, char second, char third);
    //initialize the DayOfWeek accordintly to the user input
    DayOfWeek(int dayInt);
    //Precondition: the input from 1 - 7
    //initialize the DayOfWeek accordintly to the user input
    DayOfWeek();
    //initialize the DayOfWeek to default value to 1 - MON
    void set(char first, char second, char third);
    //initialize the DayOfWeek accordintly to the user input
    void set(int dayInt);
    void input(istream &inputs);
    //the DayOfWeek set to the user input value accordintly
    void output(ostream &outs);
    //the DayOfWeek set to the user input value accordintly
    //the DayOfWeek set to the user input value accordintly
    DayOfWeek next_day();
    // Precondition: The day is defined and valid.
    // Returns the next day as an object of type DayOfWeek.
private:
    int day;
};


DayOfWeek::DayOfWeek()
{
    day = 1;
}

DayOfWeek::DayOfWeek(char first, char second, char third)
{
    first = tolower(first);
    second = tolower(second);
    third = tolower(third);

    if ((first == 'm') && (second == 'o') && (third == 'n'))
        day = 1;
    if ((first == 't') && (second == 'u') && (third == 'e'))
        day = 2;
    if ((first == 'w') && (second == 'e') && (third == 'd'))
        day = 3;
    if ((first == 't') && (second == 'h') && (third == 'u'))
        day = 4;
    if ((first == 'f') && (second == 'r') && (third == 'i'))
        day = 5;
    if ((first == 's') && (second == 'a') && (third == 't'))
        day = 6;
    if ((first == 's') && (second == 'u') && (third == 'n'))
        day = 7;
}

void DayOfWeek::set(char first, char second, char third)
{
    first = tolower(first);
    second = tolower(second);
    third = tolower(third);

    if ((first == 'm') && (second == 'o') && (third == 'n'))
        day = 1;
    if ((first == 't') && (second == 'u') && (third == 'e'))
        day = 2;
    if ((first == 'w') && (second == 'e') && (third == 'd'))
        day = 3;
    if ((first == 't') && (second == 'h') && (third == 'u'))
        day = 4;
    if ((first == 'f') && (second == 'r') && (third == 'i'))
        day = 5;
    if ((first == 's') && (second == 'a') && (third == 't'))
        day = 6;
    if ((first == 's') && (second == 'u') && (third == 'n'))
        day = 7;
}

void DayOfWeek::set(int dayInt)
{
    if (dayInt >= 1 && dayInt <= 7)
        day = dayInt;
    else
        day = 1;
}

void DayOfWeek::input(istream &inputs)
{
    char first, second, third;
    inputs >> first >> second >> third;
    first = tolower(first);
    second = tolower(second);
    third = tolower(third);

    if ((first == 'm') && (second == 'o') && (third == 'n'))
        day = 1;
    if ((first == 't') && (second == 'u') && (third == 'e'))
        day = 2;
    if ((first == 'w') && (second == 'e') && (third == 'd'))
        day = 3;
    if ((first == 't') && (second == 'h') && (third == 'u'))
        day = 4;
    if ((first == 'f') && (second == 'r') && (third == 'i'))
        day = 5;
    if ((first == 's') && (second == 'a') && (third == 't'))
        day = 6;
    if ((first == 's') && (second == 'u') && (third == 'n'))
        day = 7;
}

void DayOfWeek::output(ostream &outs)
{
    if (day >= 1 && day <= 7)
        cout << "This is day " << day << " of the week." << endl;
    else

        cout << "The input is not valid!" << endl;
}

DayOfWeek DayOfWeek::next_day()
{
    if (day >= 7)
    {
        return DayOfWeek(1);
    }
    else
    {
        return DayOfWeek(day + 1);
    }
}

DayOfWeek::DayOfWeek(int dayInt)
{
    if (dayInt >= 1 && dayInt <= 7)
        day = dayInt;
    else
        day = 1;
}

int main()
{
    DayOfWeek new_day, created_day;
    cout << "Please enter three letters for the day of week: (e.g. MON for Monday)\n";
    int i;
    new_day.input(cin);
    for (i = 1; i <= 7; i++)
    {
        new_day.output(cout);
        new_day = new_day.next_day();
    }
  
    return 0;
}
