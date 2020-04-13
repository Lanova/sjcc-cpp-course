//===========================================
// Course: CIS 054 (100616) C/C++ Programming
// Project: Bonus In-Class Assignment 4-2: Adding Digits  of a positive number(20 Points)
// Name: Olga Sirenko
// ID: 0910134
// Date: 02/19/2020
// Platform:  Linux
// Algorithm: 
//1.Take in a 4-digit number
//2.Output the sum of its digits *
//3.Remove the last digit*
//4.Repeat step 2 & 3
//===========================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//===========================================
// Fctn Name: sum_digits
// Purpose: sum digits of number & return the result
//Precondition: number is a positive number
//Postcondition: returns sum of number's digits
//===========================================
int sum_digits(int number);
//===========================================
// Fctn Name: remove_last_digit
// Purpose: remove last digit
//Precondition: number is a positive number
//Postcondition: returns the number without last digit 
//===========================================
int remove_last_digit(int number);
int factorial(int n);
int main() {
    int user_input;

    cout << "Please enter a 4-digit positive integer \n";
    cin >> user_input;
    while(user_input>0){
        cout << "Sum of digits of digits of number " << user_input<< " is " << sum_digits(user_input)<<endl;
        user_input = remove_last_digit(user_input);
        
    }
    return 0;
}
int sum_digits(int number){
    int digit;
    int sum = 0;
    while(number > 0){
        digit = number%10;
        sum+=digit;
        number = number/10;
    }
    return sum;
}
int remove_last_digit(int number){
    return number/10;
}


