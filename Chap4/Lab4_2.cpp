//===========================================
// Course: CIS 054 (100616) C/C++ Programming
// Project: Lab Assignment 4-1 Pull a Card
// Name: Olga Sirenko
// ID: 0910134
// Date: 02/19/2020
// Platform:  Linux
// Algorithm:
//picking the suit of the card
//picking the value of the card
//===========================================

/** Problems I had working on this assignment (and how I overcame these problems)
1. On my first attemt I was cout in switch statment, what would give an extra space between 
suit and value
I changed to return because a function has to return something otherweis it returns empty space  
========================================================== */


#include <iostream>
#include <iomanip>
#include <cmath>
#include <unistd.h>
using namespace std;

//===========================================
// Fctn Name: card_suit
// Purpose: pick card suit rendomly
//Postcondition: returns card suit
//===========================================
char card_suit();

//===========================================
// Fctn Name: card_value
// Purpose: pick card value rendomly
//Postcondition: returns card value
//===========================================
char card_value();

int main()
{
    char user_input  = 'n';
    cout << "Let's pull a card!\n";
    do
    {
        cout << "This time we got " << card_value() << card_suit() << endl;
        cout << "Wanna pull a card again? \"Y\" for Yes ";
        cin >> user_input;
        sleep(1);
    } while (user_input == 'y' || user_input == 'Y');
    return 0;
}

char card_suit()
{
    int suit_number;
    srand(time(0));
    suit_number = (rand() % 4) + 1;
    switch (suit_number)
    {
        case 1:
            return 'H';
            break;
        case 2:
            return 'S';
            break;
        case 3:
            return 'D';
            break;
        case 4:
            return 'C';
            break;
        default:
            return '0';
            break;
    }
}

char card_value()
{
    int value_number;
    srand(time(0));
    value_number = (rand() % 13) + 1;
    switch (value_number)
    {
        case 1:
            return 'A';
            break;
        case 2:
            return '2';
            break;
        case 3:
            return '3';
            break;
        case 4:
            return '4';
            break;
        case 5:
            return '5';
            break;
        case 6:
            return '6';
            break;
        case 7:
            return '7';
            break;
        case 8:
            return '8';
            break;
        case 9:
            return '9';
            break;
        case 10:
            return 'T';
            break;
        case 11:
            return 'J';
            break;
        case 12:
            return 'Q';
            break;
        case 13:
            return 'K';
            break;
        default:
            return '0';
            break;
    }
}
