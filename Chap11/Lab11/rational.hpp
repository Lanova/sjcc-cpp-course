//===========================================
// INTERFACE
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

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <istream>
using namespace std;

class Rational
{
public:
  //CONSTRACTORS
  Rational(int top, int bottom);
  // Function:  constractor Rational
  // Precondition: two arguments of type int passed into constractor
  // Purpose: used to set the member variables of an object to any legitimate values

  Rational(int whole_number);
  // Function:  constractor Rational
  // Precondition: a single parameter of type int
  // Purpose:  taken a single parameter and define the object initialized to the rational number whole_number/1.

  Rational();
  // Function: a default constructor Rational()
  // Precondition: none arguments were passed into constractor
  // Purpose:  initializes an object to 0 (that is, to 0/1)

  //FRIENDS OVERLOAD FUNCTIONS
  friend Rational operator+(const Rational &a, const Rational &b);
  // Precondition: none arguments were passed into constractor
  // Purpose:  return sum of a and b
  // Call: normilize()

  friend Rational operator-(const Rational &a, const Rational &b);
  // Precondition: a and b have been given values
  // Purpose:  return a minus b
  // Call: normilize()

  friend Rational operator*(const Rational &a, const Rational &b);
  // Precondition: a and b have been given values
  // Purpose:  return  multiplication of a and  b
  // Call: normilize()

  friend Rational operator/(const Rational &a, const Rational &b);
  // Precondition: a and b have been given values
  // Purpose:  returns devision of a and  b
  // Call: normilize()

  friend bool operator==(const Rational &a, const Rational &b);
  // Precondition: a and b have been given values
  // Purpose:  returns true if a and b are equal

  friend bool operator!=(const Rational &a, const Rational &b);
  // Precondition: a and b have been given values
  // Purpose:  returns true if a and b are not equal

  friend bool operator<(const Rational &a, const Rational &b);
  // Precondition: a and b have been given values
  // Purpose:  returns true if a smaller than  b

  friend bool operator<=(const Rational &a, const Rational &b);
  // Precondition: a and b have been given values
  // Purpose:  returns true if a smaller or equal than b

  friend bool operator>(const Rational &a, const Rational &b);
  // Precondition: a and b have been given values
  // Purpose:  returns true if a bigger than b

  friend bool operator>=(const Rational &a, const Rational &b);
  // Precondition: a and b have been given values
  // Purpose:  returns true if a bigger or equal than b

  friend ostream &operator<<(ostream &out, const Rational &obj);
  // Precondition:obj of type Rational exist
  // Purpose: overloads th << operator so it can be used to output values of type Rational
  // Postcondition: print numerator and denominator with '/' symbol (ex 1/2)

  friend istream &operator>>(istream &input, Rational &obj);
  // Precondition: if input is input stream
  // Purpose: overloads the >>none arguments were passed into constractor operator so it can be used to input values type Rational
  // Postcondition: if input is valid assign numerator and denominator to the obj
  // Description: Validate input:
  //                            - check if nominator not 0
  //                            - check if denominator not 0
  //                            - check if input include only

  //SETTERS AND GETTERS
  void setNumerator(int numerator);
  // Precondition: value of type int
  // Purpose:  setting numerator of the obj type Rational to the value

  int const getNumerator();
  // Precondition: no input needed
  // Purpose:  return  numerator from the obj type Rational to the value

  void setDenominator(int denominaton);
  // Precondition: value of type int
  // Purpose:  setting denominator of the obj type Rational to the value
  
  int const getDenominator();
  // Precondition: no input needed
  // Purpose:  return  denominator from the obj type Rational to the value

private:
  int numerator;
  int denominator;
  void normalize();
  // Function: normalize
  // Precondition: numerator and denominator defined
  // Purpose: check if numerator can be modulus by denominator to print whole number
  // Description: helper function

  friend void test_rational(const Rational &base, const Rational &user_input);
  // Function: test_rational
  // Purpose:  test Rational class
  // Description: Please do not change the code
  // Author: Monza Lui
};

#endif /* RATIONAL_H*/