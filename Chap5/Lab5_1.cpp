//===========================================
// Course: CIS 054 (100616) C/C++ Programming
// Project: Lab Assignment 5-1 Giving Change
// Name: Olga Sirenko
// ID: 0910134
// Date: 02/29/2020
// Platform:  Linux
// Algorithm:
//picking the suit of the card
//picking the value of the card
//===========================================
//Write a program that tells what coins to give out for as change from 1 cent to 99 cents.
// Use coin denominations of 25 cents (quarters), 10 cents (dimes), and 1 cent (pennies) only.
//Include a loop that lets the user repeat this computation for new input values until
//the user says he or she wants to end the program.
//========================================================== 

#include <iostream>
#include <iomanip>
using namespace std;

void getQuarter(int &change);
//Fctn Name: getQuarter
// Purpose: count Quarters and update change
//Precondition: take change by reference
//Postcondition: print Quarters and update change
//===========================================

void getDime(int &change);
//Fctn Name: getDime
// Purpose: count Dimes and update change
//Precondition: take change by reference
//Postcondition: print Dimes and update change
//===========================================

void getNickel(int &change);
//Fctn Name: getNickel
//Purpose: count Nickels and update change
//Precondition: take change by reference
//Postcondition: print Nickles and update change
//===========================================

void getPenny(int &change);
// Fctn Name: getPenny
//Purpose: count Pennies and update change
//Precondition: take change by reference
//Postcondition: print Pennies and update change
//===========================================

int main()
{
    int change;
    char user_input = 'n';

    cout << "Hello I am the coin machine! I will give you the least number of coins for your change.\n";
    do
    {
        try
        {
            cout << "How many cents of change do you need? (Please enter from 1 to 99)" << endl;
            cin >> change;
            if (cin.fail())
            {
                throw 50;
            }
        }
        catch (int x)
        {
            cout << "It's not an integer" << endl;
            break;
        }
        // check user input in a range 1 - 99
        if (change < 0)
        {
            cout << "You are welcome to give me money! Otherwise please enter a number from 1 to 99." << endl;
        }
        else if (change == 0)
        {
            cout << "I can't give change from 0" << endl;
        }
        else if (change > 99)
        {
            cout << "Sorry I can only give out less than 1 dollar of change." << endl;
        }
        else
        {
            cout << change << " cents can be given as:" << endl;
            getQuarter(change);
            getDime(change);
            getNickel(change);
            getPenny(change);
        }

        cout << "Want to get change again? \"Y\" for Yes ";
        cin >> user_input;
    } while (user_input == 'y' || user_input == 'Y');
    return 0;
}

void getQuarter(int &change)
{
    const int QUARTER = 25;
    int q;

    q = change / QUARTER;
    change = change % QUARTER;

    if (q == 1)
        cout << q << " Quarter" << endl;
    else if (q > 1)
        cout << q << " Quarters" << endl;
    else
        return;
}
void getDime(int &change)
{
    const int DIME = 10;
    int d;
    d = change / DIME;
    change = change % DIME;
    if (d == 1)
        cout << d << " Dime" << endl;
    else if (d > 1)
        cout << d << " Dimes" << endl;
    else
        return;
}
void getNickel(int &change)
{
    const int NICKLE = 5;
    int n;
    n = change / NICKLE;
    change = change % NICKLE;

    if (n == 1)
        cout << n << " Nickle" << endl;
    else if (n > 1)
        cout << n << " Nickles" << endl;
    else
        return;
}

void getPenny(int &change)
{
    const int PENNIE = 1;
    int p;
    p = change / PENNIE;
    change = change % PENNIE;

    if (p == 1)
        cout << p << " Penny" << endl;
    else if (p > 1)
        cout << p << " Pennies" << endl;
    else
        return;
}
