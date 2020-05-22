//===========================================
// IMPLEMENTATION
//===========================================
// Course: CIS 054 (100616) C/C++ Programming
// Bonus Assignment: Lab Assignment 13-2 Animal Kingdom
// Name: Olga Sirenko
// ID: 0910134
// Date: 05/10/2020
// Platform:  Linux
// ===========================================
// Include:
//      1. In summary, you will have 8 member functions in your class:
//          1.1. Default constructor
//          1.2. Constructor that accepts an integer parameter to set the max_size
//          1.3 Copy constructor
//          1.4 Destructor
//          1.5 Overload = operator
//          1.6 add_temperature
//          1.7 full (no change in its implementation)
//          1.8 Overloading operator << (nothing shall need to change in its implementation)
//      2. The class has 3 member variables
//          2.1 size - current size of your array
//          2.2 max_size - max size the array will hold
//          2.3 list - dynamic array/pointer to

#include <iostream>
#include <istream>
#include "templist.h"
using namespace std;

//CONSTRACTORS
// Function:  Default constractor TemperatureList
// Precondition: none arguments were passed into constractor
// Purpose:  initializes an object to an empty list.
TemperatureList::TemperatureList()
{
	size = 0;
	max_size = 0;
	list = NULL;
}

// Function: constractor TemperatureList
// Precondition: one int positive arguments passed into constractor
// Purpose: set maximum size of the list
TemperatureList::TemperatureList(int max) : max_size(max)
{
	size = 0;
	list = new double[max];
}

// Function: copy constractor
// Precondition: one TemperatureList object passed into constractor by reference
// Purpose: copy one TeperatureList object to another
TemperatureList::TemperatureList(const TemperatureList &copy)
{
	size = copy.size;
	max_size = copy.max_size;
	if (size > 0)
	{
		list = new double[max_size];
		for (int i = 0; i < max_size; i++)
		{
			list[i] = copy.list[i];
		}
	}
	else
	{
		list = NULL;
	}
}

// Function: destructor
// Precondition: suppose that memory was allocated previously
// Purpose: dealocate the list memory
TemperatureList::~TemperatureList()
{
	delete[] list;
}

//OVERLOADS
// Function: overload the = operator
// Precondition: one TemperatureList object passed into constractor by reference
// Purpose: Overloading assignment operator
void TemperatureList::operator=(const TemperatureList &copy)
{
	delete[] list;
	size = copy.size;
	max_size = copy.max_size;
	if (size > 0)
	{
		list = new double[max_size];
		for (int i = 0; i < max_size; i++)
		{
			list[i] = copy.list[i];
		}
	}
	else
	{
		list = NULL;
	}
}

// Function: overloads the << operator
// Precondition: If outs is a file output stream, then outs has already been connected to a file.
// Purpose: Overloads the << operator so it can be used to output values of type TemperatureList.
// Format:  Temperatures are output one per line.
ostream &operator<<(ostream &outs, const TemperatureList &obj)
{
	for (int i = 0; i < obj.size; i++)
		outs << obj.list[i] << " F\n";
	return outs;
}

// MODIFIER
// Function: add_temperature
//Precondition: The list is not full.
//Postcondition: The temperature has been added to the list
//Call: full()
void TemperatureList::add_temperature(double temperature)
{
	if (full())
	{
		cout << "Error: adding to a full list.\n";
		exit(1);
	}
	else
	{
		list[size] = temperature;
		size++;
	}
}

//SETTERS
// Function: set_list
//Precondition: given the positive int as a position, the list is not ful
//Postcondition: The temperature has been added to the list into specified place
bool TemperatureList::set_list(int position, double value)
{
	if (size >= position)
	{
		list[position - 1] = value;
		return true;
	}
	else
	{
		return false;
	}
}

//GETTERS
// Function: get_size
//Precondition: the list has been inisialized
//Postcondition: return current size of the list
int TemperatureList::get_size()
{
	return size;
}

// Function: get_last
//Precondition: the list has been inisialized
//Postcondition: return the last element of the list, or 0 if the list is empty, with a warning output
//Call: empty()
double TemperatureList::get_last()
{
	if (empty())
	{
		cout << "The list is empty\n";
		return 0;
	}
	else
	{
		return list[size - 1];
	}
}

// Function:  get_list_element
//Precondition: the list has been inisialized
//Postcondition: return element at the given position, or 0 if the list is empty, with a warning output
double TemperatureList::get_list_element(int position)
{
	if (size >= position)
	{
		return list[position - 1];
	}
	else
	{
		cout << "list does not exist\n";
		return 0;
	}
}

//VALIDATORS
// Function:  full
//Precondition: the list has been inisialized
//Postcondition: Returns true if the list is full; false otherwise.
bool TemperatureList::full() const
{
	return (size >= max_size);
}

// Function:  full
//Precondition: the list has been inisialized
//Postcondition: Returns true if the list is empty ( size == 0); false otherwise.
bool TemperatureList::empty() const
{
	return (size == 0);
}
