//===========================================
// MAIN
//===========================================
// Course: CIS 054 (100616) C/C++ Programming
// Lab Assignment 12-1 TemperatureList Class with Dynamic Array
// Name: Olga Sirenko
// ID: 0910134
// Date: 05/03/2020
// Platform:  Linux
// ===========================================

#include <iostream>
#include "templist.h"
using namespace std;

// ================================================
// Function: main
// Purpose:	Test program for lab12-2 TemperatureList Class with Dynamic Array
// Author: 	Monza Lui
// ================================================
int main()
{

	TemperatureList temp_a(2);

	temp_a.add_temperature(23.5);
	temp_a.add_temperature(24.6);
	cout << temp_a;

	TemperatureList temp_b = temp_a;
	cout << temp_b;

	temp_a = TemperatureList();
	cout << "Now there's no temperatures in a.\n";
	cout << temp_a;
	cout << "How about temperatures in b?\n";
	cout << temp_b;

	return 0;
}