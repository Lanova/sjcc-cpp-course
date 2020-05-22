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

#ifndef TEMPLIST_H
#define TEMPLIST_H

#include <iostream>
#include <istream>
#include <cstdlib>
using namespace std;

class TemperatureList
{
public:
   //CONSTRACTORS
   TemperatureList();
   // Function:  Default constractor TemperatureList
   // Precondition: none arguments were passed into constractor
   // Purpose:  initializes an object to an empty list.

   TemperatureList(int max);
   // Function: constractor TemperatureList
   // Precondition: one int positive arguments passed into constractor
   // Purpose: set maximum size of the list

   TemperatureList(const TemperatureList &copy);
   // Function: copy constractor
   // Precondition: one TemperatureList object passed into constractor by reference
   // Purpose: copy one TeperatureList object to another

   ~TemperatureList();
   // Function: destructor
   // Precondition: suppose that memory was allocated previously
   // Purpose: dealocate the list memory

   //OVERLOADS
   void operator=(const TemperatureList &copy);
   // Function: overload the = operator
   // Precondition: one TemperatureList object passed into constractor by reference
   // Purpose: Overloading assignment operator

   friend ostream &operator<<(ostream &outs, const TemperatureList &obj);
   // Function: overloads the << operator
   //Precondition: If outs is a file output stream, then outs has already been connected to a file.
   // Purpose: Overloads the << operator so it can be used to output values of type TemperatureList.
   //Format:  Temperatures are output one per line.

   // MODIFIER
   void add_temperature(double temperature);
   // Function: add_temperature
   //Precondition: The list is not full.
   //Postcondition: The temperature has been added to the list.
   //Call: full()

   //SETTERS
   bool set_list(int position, double value);
   // Function: set_list
   //Precondition: given the positive int as a position, the list is not ful
   //Postcondition: The temperature has been added to the list into specified place

   //GETTERS
   int get_size();
   // Function: get_size
   //Precondition: the list has been inisialized
   //Postcondition: return current size of the list

   double get_last();
   // Function: get_last
   //Precondition: the list has been inisialized
   //Postcondition: return the last element of the list, or 0 if the list is empty, with a warning output
   //Call: empty()

   double get_list_element(int position);
   // Function:  get_list_element
   //Precondition: the list has been inisialized
   //Postcondition: return element at the given position, or 0 if the list is empty, with a warning output

   //VALIDATORS
   bool full() const;
   // Function:  full
   //Precondition: the list has been inisialized
   //Postcondition: Returns true if the list is full; false otherwise.

   bool empty() const;
   // Function:  full
   //Precondition: the list has been inisialized
   //Postcondition: Returns true if the list is empty ( size == 0); false otherwise.

private:
   double *list;      //dynamic array/pointer to
   int size;          //current size of array
   int max_size = 50; // max size the array will hold
};
#endif /* TEMPLIST_H*/