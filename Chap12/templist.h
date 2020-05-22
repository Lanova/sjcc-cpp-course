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
//      1. In summary, you will have 8 member functions in your class:
//          1.1. Default constructor
//          1.2. Constructor that accepts an integer parameter to set the max_size 
//          1.3 Copy constructor
//          1.4 Destructor
//          1.5 Overload = operator
//          1.6 add_temperature
//          1.7 full (no change in its implementation)
//          1.8 Overloading operator << (nothing shall need to change in its implementation)
//      2. You will have 3 member variables in your class
//          2.1 size - current size of your array
//          2.2 max_size - max size the array will hold
//          2.3 list - dynamic array/pointer to

// Requirements:
//      1. Replace the array list[MAX_LIST_SIZE]  with a dynamic array
//      2. Add a max_size member variable that sets the max number of elements allowed in the array
//      3. Add a constructor that accepts an integer parameter that specifies max_size 
//      4. Add the big three (copy constractor, =operator, destructor)
//      5. Change the implementation of the class to make sure no memory leak happens and the class functions as expected
//      6. Separate the class into templist.h and templist.cpp files -DONE
//      7. Follow the ADT (Abstract Data Type) guideline to implement the required class
//      8. Comment well in your program and any functions you use

#ifndef TEMPLIST_H
#define TEMPLIST_H

#include <iostream>
#include <istream>
#include <cstdlib>
using namespace std;


  class TemperatureList
  {
  public:
     TemperatureList( );
     //Initializes the object to an empty list.

     void add_temperature(double temperature);
     //Precondition: The list is not full.
     //Postcondition: The temperature has been added to the list.

     bool full( ) const;
     //Returns true if the list is full; false otherwise.

     friend ostream& operator <<(ostream& outs,
                                 const TemperatureList& the_object);
     //Overloads the << operator so it can be used to output values of
     //type TemperatureList. Temperatures are output one per line.
     //Precondition: If outs is a file output stream, then outs
     //has already been connected to a file.

  private:
        int max_size = 50; // max size the array will hold
     double list[max_size]; //dynamic array/pointer to
     int size; //current size of array
     
  };
#endif /* TEMPLIST_H*/