//===========================================
// Course: CIS 054 (100616) C/C++ Programming
// Assignment: Week 2 - Lab Assignment 2-1 Sum and Average Program
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
    int number;
    double count = 0.0;
    int sum = 0;
    double avr = 0.0;
    int pos_sum = 0;
    double pos_count = 0.0;
    double pos_avr = 0.0;
    int neg_sum = 0;
    double neg_count = 0.0;
    double neg_avr = 0.0;
    
    //Input
    cout << "Please enter 10 number separeted by space \n";
    while (count < 10) { 
        cin >> number;          
        sum += number;      // ALL NUMBERS
        count++;
        if(number >= 0){
            pos_sum += number; // POSITIVE NUMBERS
            pos_count++;
            pos_avr = pos_sum / pos_count;
        }
        else{
            neg_sum += number;  //NEGATIVE NUMBERS
            neg_count++;
            neg_avr = neg_sum / neg_count;
        }
    }
    //Canculation all nums
    avr = sum/count;
    cout << fixed << setprecision(2);
    //Output
    cout << "For positive numbers, occurrence = " << pos_count << " sum = " << pos_sum << " and average = " << pos_avr <<endl;
    cout << "For negative numbers, occurrence = " << neg_count << " sum = " << neg_sum << " and average = " << neg_avr <<endl;
    cout << "For all numbers, occurrence = " << count << " sum = " << sum << " and average = " << avr <<endl;

    return 0;
 }

 /* ==========================================================

Problems I had working on this assignment (and how I overcame these problems)

1. Show decimal 2 desimal nums after . initialized avr and count to double and set to 0.0

========================================================== */



