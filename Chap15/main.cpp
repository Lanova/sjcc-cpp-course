//===========================================
// MAIN
//===========================================
// Course: CIS 054 (100616) C/C++ Programming
// Bonus Assignment: Lab Assignment 13-2 Animal Kingdom
// Name: Olga Sirenko
// ID: 0910134
// Date: 05/10/2020
// Platform:  Linux
// ===========================================
// Description:
//          This bonus assignment can give you a max of 40 points.
//          This assignment is an opportunity for you to practice using virtual functions.
//			You are to implement 7 simple classes with 0 or 1 member variable:
//          1. Animal (Grandparent)
//                1. Mammal (Parent)
//                      1. Human (Grandkid)
//                      2. Cat (Grandkid)
//                2. Bird (Parent)
//                      1. Owl (Grandkid)
//                      2. Duck (Grandkid)
#include <iostream>
#include "animal.h"
using namespace std;

int main()
{
	Cat cat;
	Human human("English");
	Animal *animals[4];
	animals[0] = new Duck;
	animals[1] = new Owl;
	animals[2] = &cat;
	animals[3] = &human;
	for (int i = 0; i < 4; i++)
	{
		animals[i]->make_sound();
	}
	delete animals[0];
	delete animals[1];
	return 0;
}
