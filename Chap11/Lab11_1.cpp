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
// Example:
//      Welcome to the Rational World of Wonders!
// Please enter a rational number for this calculation:
// 3/0
// Please enter a valid rational number (e.g. 1/4)
// 3-4
// Please enter a valid rational number (e.g. 1/4)
// 1/2
// 1/2 + 1/2 = 1
// 1/2 - 1/2 = 0
// 1/2 * 1/2 = 1/4
// 1/2 / 1/2 = 1
// 1/2 == 1/2 : true
// 1/2 < 1/2 : false
// 1/2 <= 1/2 : true
// 1/2 > 1/2 : falseuh
// 1/2 >= 1/2 : true

// Problems:
//

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

//CONSTRACTORS
// Function:  constractor Rational
// Precondition: two arguments of type int passed into constractor
// Purpose: used to set the member variables of an object to any legitimate values
Rational::Rational(int top, int bottom)
{
  if (bottom < 0)
  {
    denominator *= -1;
    numerator *= -1;
  }
  else
  {
    numerator = top;
    denominator = bottom;
  }
}

// Function:  constractor Rational
// Precondition: a single parameter of type int
// Purpose:  taken a single parameter and define the object initialized to the rational number whole_number/1.
Rational::Rational(int whole_number)
{
  numerator = whole_number;
  denominator = 1;
}

// Function: a default constructor Rational()
// Precondition: none arguments were passed into constractor
// Purpose:  initializes an object to 0 (that is, to 0/1)
Rational::Rational()
{
  numerator = 0;
  denominator = 1;
}

//NORMALIZE
// Function: normalize
// Precondition: numerator and denominator defined
// Purpose: check if numerator can be modulus by denominator to print whole number
// Description: helper function
void Rational::normalize()
{
  int remainder = numerator % denominator;
  int old = denominator;
  while (remainder != 0)
  {
    int temp = remainder;
    remainder = old % remainder;
    old = temp;
  }
  numerator = numerator / old;
  denominator = denominator / old;
}

//SETTERS & GETTERS
// Precondition: value of type int
// Purpose:  setting numerator of the obj type Rational to the value
void Rational::setNumerator(int num)
{
  numerator = num;
}

// Precondition: no input needed
// Purpose:  return  numerator from the obj type Rational to the value
int const Rational::getNumerator()
{
  return numerator;
}

// Precondition: value of type int
// Purpose:  setting denominator of the obj type Rational to the value
void Rational::setDenominator(int den)
{
  if (den == 0)
  {
    cout << "Can not devide by 0" << endl;
  }
  else
  {
    denominator = den;
  }
}

// Precondition: no input needed
// Purpose:  return  denominator from the obj type Rational to the value
int const Rational::getDenominator()
{
  return denominator;
}

//FRIEND OVERLOAD FUNCTIONS
// Precondition: none arguments were passed into constractor
// Purpose:  return sum of a and b
// Call: normilize()
Rational operator+(const Rational &a, const Rational &b)
{
  Rational temp;
  int temp1;
  int temp2;
  temp1 = a.numerator * b.denominator;
  temp2 = a.denominator * b.numerator;
  temp.numerator = temp1 + temp2;
  temp.denominator = a.denominator * b.denominator;
  temp.normalize();
  return temp;
}

// Precondition: a and b have been given values
// Purpose:  return a minus b
// Call: normilize()
Rational operator-(const Rational &a, const Rational &b)
{
  Rational temp;
  temp.numerator = (a.numerator * b.denominator) - (b.numerator * a.denominator);
  temp.denominator = a.denominator * b.denominator;
  temp.normalize();
  return temp;
}

// Precondition: a and b have been given values
// Purpose:  return  multiplication of a and  b
// Call: normilize()
Rational operator*(const Rational &a, const Rational &b)
{
  Rational temp;
  temp.numerator = a.numerator * b.numerator;
  temp.denominator = a.denominator * b.denominator;
  temp.normalize();
  return temp;
}

// Precondition: a and b have been given values
// Purpose:  returns devision of a and  b
// Call: normilize()
Rational operator/(const Rational &a, const Rational &b)
{
  Rational temp;
  int temp2d;
  int temp2n;
  temp2n = b.denominator;
  temp2d = b.numerator;
  temp.numerator = a.numerator * temp2n;
  temp.denominator = a.denominator * temp2d;
  temp.normalize();
  return temp;
}

// Precondition: a and b have been given values
// Purpose:  returns true if a and b are equal
bool operator==(const Rational &a, const Rational &b)
{
  if ((a.numerator * b.denominator) == (a.denominator * b.numerator))
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Precondition: a and b have been given values
// Purpose:  returns true if a and b are not equal
bool operator!=(const Rational &a, const Rational &b)
{
  if ((a.numerator * b.denominator) != (a.denominator * b.numerator))
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Precondition: a and b have been given values
// Purpose:  returns true if a smaller than  b
bool operator<(const Rational &a, const Rational &b)
{
  int temp1 = a.numerator * b.denominator;
  int temp2 = a.denominator * b.numerator;
  return (temp1 < temp2);
}

// Precondition: a and b have been given values
// Purpose:  returns true if a bigger than b
bool operator>(const Rational &a, const Rational &b)
{
  int temp1 = a.numerator * b.denominator;
  int temp2 = a.denominator * b.numerator;
  return (temp1 > temp2);
}
// Precondition: a and b have been given values
// Purpose:  returns true if a smaller or equal than b
bool operator<=(const Rational &a, const Rational &b)
{
  return ((a < b) || (a == b));
}

// Precondition: a and b have been given values
// Purpose:  returns true if a bigger or equal than b
bool operator>=(const Rational &a, const Rational &b)
{
  return ((a > b) || (a == b));
}

// Precondition:obj of type Rational exist
// Purpose: overloads th << operator so it can be used to output values of type Rational
// Postcondition: print numerator and denominator with '/' symbol (ex 1/2)
ostream &operator<<(ostream &out, const Rational &obj)
{
  out << obj.numerator;
  if (obj.numerator != 0 && obj.denominator != 1)
  {
    out << "/" << obj.denominator;
  }
  return out;
}

// Precondition: if input is input stream
// Purpose: overloads the >>none arguments were passed into constractor operator so it can be used to input values type Rational
// Postcondition: if input is valid assign numerator and denominator to the obj
// Description: Validate input:
//                            - check if nominator not 0
//                            - check if denominator not 0
//                            - check if input include only
istream &operator>>(istream &input, Rational &obj)
{
  int num, den;
  char symb;
  input >> num >> symb >> den;

  if (symb != '/')
  {
    cout << "Invalid Input. Please enter a valid rational number (e.g. 1/4)\n";
    // input.ignore(1);
  }
  if (num == 0)
  {
    cout << "Zero can't be devided \n";
  }
  else if (den == 0)
  {
    cout << "Denominator can't be zero. Can not devide by 0\n";
  }
  else
  {
    obj.numerator = num;
    obj.denominator = den;
  }
  return input;
}

// ================================================
// Function: test_rational
// Purpose:  test Rational class
// Description: Please do not change the code
// Author: Monza Lui
// ================================================
void test_rational(const Rational &base, const Rational &user_input)
{
  cout << user_input << " + " << base << " = " << (user_input + base) << endl;
  cout << user_input << " - " << base << " = " << (user_input - base) << endl;
  cout << user_input << " * " << base << " = " << (user_input * base) << endl;
  cout << user_input << " / " << base << " = " << (user_input / base) << endl;
  cout << user_input << " == " << base << " : ";
  (user_input == base) ? cout << "true\n" : cout << "false\n";
  cout << user_input << " < " << base << " : ";
  (user_input < base) ? cout << "true\n" : cout << "false\n";
  cout << user_input << " <= " << base << " : ";
  (user_input <= base) ? cout << "true\n" : cout << "false\n";
  cout << user_input << " > " << base << " : ";
  (user_input > base) ? cout << "true\n" : cout << "false\n";
  cout << user_input << " >= " << base << " : ";
  (user_input >= base) ? cout << "true\n" : cout << "false\n";
}

// ================================================
// Function: main
// Purpose:  run test on Rational class
// Description: Please do not change the code
// Author: Monza Lui
// ================================================
int main()
{
  Rational a;
  Rational b(1, 2);

  cout << "Welcome to the Rational World of Wonders!\n";
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