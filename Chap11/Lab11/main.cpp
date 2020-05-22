//===========================================
// MAIN
//===========================================
// Course: CIS 054 (100616) C/C++ Programming
// Lab Assignment 11-1 Rational Numbers
// Name: Olga Sirenko
// ID: 0910134
// Date: 04/15/2020
// Platform:  Linux
// ===========================================
// Include:
//        1.1 a constructor with two arguments
//        1.2 a constructor that has only a single parameter of type int;
//        1.3 a default constructor that initializes an object to 0 (that is, to 0/1).
// Overload:
//        2.1 the input and output operators >> and <<
//        2.2 following operators ==, <, <=, >, >=, +, -, *, and /.
// Requirements:
//      1.DOWNLOAD TEST PROGRAM
//      2.Follow the ADT (Abstract Data Type) guideline to implement the required class
//      3.Comment well in your program and any functions you use


// ================================================
// Function: main
// Purpose:  run test on Rational class
// Description: Please do not change the code
// Author: Monza Lui
// ================================================
#include <iostream>
#include <istream>
#include "rational.hpp"
using namespace std;

int main()
{
  Rational a;
  Rational b(1, 2);

  cout << "Welcome to the Rational World of Waonders!\n";
  cout << "Please enter a rational number for this calculation:\n";
  cin >> a;
  if (a.getNumerator() == 0)
  {
    cout << "Error\n";
  }
  else
  {
    test_rational(b, a);
  }
  return 0;
}