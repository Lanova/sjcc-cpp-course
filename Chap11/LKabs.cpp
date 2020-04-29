/*
* Rational.h
*
*/

#ifndef RATIONAL_H_
#define RATIONAL_H_
#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
using namespace std;
class Rational
{
public:
    Rational();
    Rational(int whole_number);
    Rational(int num, int denom);
    friend Rational operator*(const Rational &rational1, const Rational &rational2);
    friend Rational operator/(const Rational &rational1, const Rational &rational2);
    friend Rational operator+(const Rational &rational1, const Rational &rational2);
    friend Rational operator-(const Rational &rational1, const Rational &rational2);
    friend bool operator==(const Rational &rational1, const Rational &rational2);
    friend bool operator!=(const Rational &rational1, const Rational &rational2);
    string toString();

private:
    int numerator;
    int denominator;
    void reduce();
};

#endif /* RATIONAL_H_ */

Rational.cpp

/*
* Rational.cpp
*
*/

#include “Rational.h”

Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int whole_number)
{
    numerator = whole_number;
    denominator = 1;
}

Rational::Rational(int num, int denom)
{
    numerator = num;
    denominator = denom;

    if (denominator < 0)
    {
        denominator *= -1;
        numerator *= -1;
    }

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

Rational operator*(const Rational &rational1, const Rational &rational2)
{
    Rational ret;
    ret.numerator = rational1.numerator * rational2.numerator;
    ret.denominator = rational1.denominator * rational2.denominator;
    ret.reduce();
    return ret;
}

Rational operator/(const Rational &rational1, const Rational &rational2)
{
    Rational ret;
    int temp_rational2_denom;
    int temp_rational2_num;
    temp_rational2_num = rational2.denominator;
    temp_rational2_denom = rational2.numerator;
    ret.numerator = rational1.numerator * temp_rational2_num;
    ret.denominator = rational1.denominator * temp_rational2_denom;
    ret.reduce();
    return ret;
}

Rational operator+(const Rational &rational1, const Rational &rational2)
{
    Rational ret;
    int temp1_num;
    int temp2_num;
    temp1_num = rational1.numerator * rational2.denominator;
    temp2_num = rational1.denominator * rational2.numerator;
    ret.numerator = temp1_num + temp2_num;
    ret.denominator = rational1.denominator * rational2.denominator;
    ret.reduce();
    return ret;
}

Rational operator-(const Rational &rational1, const Rational &rational2)
{
    Rational ret;
    ret.numerator = (rational1.numerator * rational2.denominator) – (rational2.numerator * rational1.denominator);
    ret.denominator = rational1.denominator * rational2.denominator;
    ret.reduce();
    return ret;
}

bool operator==(const Rational &rational1, const Rational &rational2)
{
    if ((rational1.numerator * rational2.denominator) == (rational1.denominator * rational2.numerator))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator!=(const Rational &rational1, const Rational &rational2)
{
    if ((rational1.numerator * rational2.denominator) != (rational1.denominator * rational2.numerator))
    {
        return true;
    }
    else
    {
        return false;
    }
}

string Rational::toString()
{
    reduce();
    ostringstream result;
    result << numerator << “/” << denominator;
    return result.str();
}

void Rational::reduce()
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