//===========================================
// Course: CIS 054 (100616) C/C++ Programming
// Project: Lab Assignment 5_2 Life Path Number
// Names: Olga Sirenko & Huy Nguyen
// Date: 02/26/2020
// Platform:  Linux
// Algorithm:
// Write a program to offer the service to calculate your user’s life path number.
// How to calculate life path number:
// 1.Birth day + birth month + birth year
// 2.Add all the digits together
// 3.Repeat step 2 until you get a single digit
// ========================================================== */
/* ==========================================================
Problems We had working on this assignment (and how I overcame these problems)
1. infinite loop in sum_all_digits() fixed by  num /= 10;
2. we didn't sum bday, bmonth and byear in calculate_life_path_number()
 fixed   int sumNum = bday + bmonth + byear;
========================================================== */
#include <iostream>
#include <iomanip>
using namespace std;

//===========================================
// Fctn Name: get_bday_input
// Purpose: take the input from the user
//Precondition: date of birth (format of day/month/year)
//Postcondition: store values
//Calls:  n/a
//===========================================
void get_bday_input(int &bday, int &bmonth, int &byear);

//===========================================
// Fctn Name: calculate_life_path_number
// Purpose: call final result
//Precondition: date of birth (format of day/month/year)
//Postcondition: int final result
//Calls: sum_all_digits
//===========================================
int calculate_life_path_number(int bday, int bmonth, int byear);

//===========================================
// Fctn Name: sum_to_single_digit
// Comments: WE DON'T USE
//===========================================
int sum_to_single_digit(int num);

//===========================================
// Fctn Name:  sum_all_digits
// Purpose: sum all digits into number
//Precondition: number
//Postcondition: number or a digit is sum of digits
//Calls: n/a
//===========================================
int sum_all_digits(int num);

int main()
{

    int day = 0, month = 0, year = 0;

    get_bday_input(day, month, year);
    cout << "your life path number is " << calculate_life_path_number(day, month, year)<< endl;
}

void get_bday_input(int& bday, int &bmonth, int &byear)
{
    cout << "Please enter your birthday (day month year)" << endl;
    cin >> bday >> bmonth >> byear;
}

int calculate_life_path_number(int bday, int bmonth, int byear)
{
    int sumNum = bday + bmonth + byear;
    int oneNum = sum_all_digits(sumNum);

    if (oneNum == 11 || oneNum == 22)
    {
      cout << "Master Number and it is ";
      return oneNum;
     
            
    }
    else if(oneNum < 9){
         return oneNum;
    }
    else
    {
       sum_all_digits(oneNum);
    }
   
}

int sum_all_digits(int num)
{
    int digit;
    int sum = 0;
    while (num > 0)
    {
        digit = num % 10;
        sum += digit;
        num /= 10;
    }
    return sum;
}