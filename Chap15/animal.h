//===========================================
// INTERFACE
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
#include <cstdlib>
using namespace std;

#ifndef ANIMAL_H
#define ANIMAL_H
class Animal // parent class - base for Mammals and Bird
{
public:
   // Function:  Default constractor Animals
   // Precondition: none
   // Purpose:  initializes an animal object
   Animal();

   // Function:  virtual make_sound
   // Precondition: none
   // Purpose:  base function for creating sounds, overriten in the inherited classes
   virtual void make_sound() const;
};
#endif /* ANIMAL_H*/

// ==========================================================================================
#ifndef MAMMAL_H
#define MAMMAL_H
class Mammal : public Animal // base for Hunan and Cat
{
public:
   // Function:  Default constractor Mammal
   // Precondition: none
   // Purpose:  initializes an Mammal object
   Mammal();
};
#endif /*MAMMAL_H*/

// ==========================================================================================
#ifndef HUMAN_H
#define HUMAN_H
class Human : public Mammal
{
public:
   // Function:  Default constractor Human
   // Precondition: none
   // Purpose:  initializes an Human object
   Human();

   // Function: constractor with str variable
   // Precondition:  string as input
   // Purpose:  set member variable language to given value
   Human(string Language);

   // Function:  virtual make_sound
   // Precondition: none
   // Purpose:  creating sound for Human clkass, overriten in the parent classes
   virtual void make_sound() const;

protected:
   string language;
};
#endif /*HUMAN_H*/

// ==========================================================================================
#ifndef CAT_H
#define CAT_H
class Cat : public Mammal
{
public:
   // Function:  Default constractor Cat
   // Precondition: none
   // Purpose:  initializes an Cat object
   Cat();

   // Function:  virtual make_sound
   // Precondition: none
   // Purpose:  creating sound for Cat class, overriten in the parent classes
   virtual void make_sound() const;
};
#endif /*CAT_H*/

// ==========================================================================================
#ifndef BIRD_H
#define BIRD_H
class Bird : public Animal // base for Owl and Duck
{
public:
   // Function:  Default constractor Bird
   // Precondition: none
   // Purpose:  initializes an Bird object
   Bird();
};
#endif /*BIRD_H*/

// ==========================================================================================
#ifndef OWL_H
#define OWL_H
class Owl : public Bird
{
public:
   // Function:  Default constractor Owl
   // Precondition: none
   // Purpose:  initializes an Owl object
   Owl();

   // Function:  virtual make_sound
   // Precondition: none
   // Purpose:  creating sound for Owl class, overriten in the parent classes
   virtual void make_sound() const;
};
#endif /*OWL_H*/

// ==========================================================================================
#ifndef DUCK_H
#define DUCK_H
class Duck : public Bird // parent class - base for Mammals and Bird
{
public:
   // Function:  Default constractor Duck
   // Precondition: none
   // Purpose:  initializes an Duck objec
   Duck();

   // Function:  virtual make_sound
   // Precondition: none
   // Purpose:  creating sound for Duck class, overriten in the parent classes
   virtual void make_sound() const;
};
#endif /*DUCK_H*/