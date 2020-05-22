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
//			You are to implement 7 simple classes with 0 or 1 member variable:
//          1. Animal (Grandparent)
//                1. Mammal (Parent)
//                      1. Human (Grandkid)
//                      2. Cat (Grandkid)
//                2. Bird (Parent)
//                      1. Owl (Grandkid)
//                      2. Duck (Grandkid)

#include <iostream>
#include <istream>
#include "animal.h"
using namespace std;

// Function:  Default constractor Animals
// Precondition: none
// Purpose:  initializes an animal object
Animal::Animal() {}

// Function:  virtual make_sound
// Precondition: none
// Purpose:  base function for creating sounds, overriten in the inherited classes
void Animal::make_sound() const {}

// Function:  Default constractor Mammal
// Precondition: none
// Purpose:  initializes an Mammal object
Mammal::Mammal() {}

// Function:  Default constractor Human
// Precondition: none
// Purpose:  initializes an Human object
Human::Human() {}

// Function: constractor with str variable
// Precondition:  string as input
// Purpose:  set member variable language to given value
Human::Human(string TheLanguage) : language(TheLanguage) {}

// Function:  virtual make_sound
// Precondition: none
// Purpose:  creating sound for Human clkass, overriten in the parent classes
void Human::make_sound() const
{
	cout << "I speak " << language << endl;
}

// Function:  Default constractor Cat
// Precondition: none
// Purpose:  initializes an Cat object
Cat::Cat() {}

// Function:  virtual make_sound
// Precondition: none
// Purpose:  creating sound for Cat class, overriten in the parent classes
void Cat::make_sound() const
{
	cout << "I meow" << endl;
}

// Function:  Default constractor Bird
// Precondition: none
// Purpose:  initializes an Bird object
Bird::Bird() {}

// Function:  Default constractor Owl
// Precondition: none
// Purpose:  initializes an Owl object
Owl::Owl() {}

// Function:  virtual make_sound
// Precondition: none
// Purpose:  creating sound for Owl class, overriten in the parent classes
void Owl::make_sound() const
{
	cout << "I hoot" << endl;
}

// Function:  Default constractor Duck
// Precondition: none
// Purpose:  initializes an Duck objec
Duck::Duck() {}

// Function:  virtual make_sound
// Precondition: none
// Purpose:  creating sound for Duck class, overriten in the parent classes
void Duck::make_sound() const
{
	cout << "I quack" << endl;
}
