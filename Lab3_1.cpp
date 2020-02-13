//===========================================
// Course: CIS 054 (100616) C/C++ Programming
// Assignment: Week 3 - Lab Assignment 3 Christmas Tree
// Name: Olga Sirenko
// ID: 0910134
// Date: 02/05/1989
// Platform:  Linux
// ===========================================

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    char user_input = 'n';
    int rows = 6;
    int columns = 11;
    int middle = columns/2+1;
    int left_limit, right_limit;

    do{ 
        cout << "Merry X'mas!\n" ;
        // printing tree
        for ( int i = 0; i<=rows-1; i++) {
            left_limit = middle - i;
            right_limit = middle + i;
            for(int x = 1; x<=columns; x++) {
                if (left_limit <= x && x <= right_limit) {
                    cout << "*";
                } else {
                    cout << "-";
                }
            }
            cout<<endl;
        }
        

    
    // user input to repeat the programm
        cout << "Do you want to see the tree again? Please enter \"Y\" for Yes "; 
        cin>> user_input;
    } while(user_input == 'y'|| user_input == 'Y');
    
    return 0;
}

 /* ==========================================================

Problems I had working on this assignment (and how I overcame these problems)

1. Show decimal 2 desimal nums after . initialized avr and count to double and set to 0.0

========================================================== */



