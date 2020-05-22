//===========================================
// IMPLEMENTATION
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



// DISPLAY 11.10 Program for a Class with an Array Member
// This is the definition for a class TemperatureList.
// Values of this type are lists of Fahrenheit temperatures.



//This is the implementation for the class TemperatureList.
#include <iostream>
#include <istream>
#include "templist.h"

using namespace std;
	TemperatureList::TemperatureList( ) : size(0)
	{
		//Body intentionally empty.
	}

	void TemperatureList::add_temperature(double temperature)
	{//Uses iostream and cstdlib:
		if ( full() )
		{
			cout << "Error: adding to a full list.\n";
			exit(1);
		}
		else
		{
			list[size] = temperature;
			size = size + 1;
 		}
 	}
	bool TemperatureList::full( ) const
	{
			return (size == max_size);
	}
	//Uses iostream:
	ostream& operator <<(ostream& outs, const TemperatureList& the_object)
	{
		for (int i = 0; i < the_object.size; i++)
			outs << the_object.list[i] << " F\n";
		return outs;
}
