// File: 	stack.h
// Purpose:	Interface for the class Stack of double number
// Author:	Monza Lui
// Date:	Nov 30, 2019
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
using namespace std;

struct Node {
	double number;
	Node *next;
};
typedef Node* NodePointer;

class Stack {
private:
	NodePointer top;
public:
	// == Friends ==
	// Purpose: Output from top node
	friend ostream& operator << (ostream& outs, const Stack& the_stack);
	// == Constructors ==
	// Default constructor, initialize to an empty stack
	Stack();
	// Copy constructor, make an exact copy of the_stack
	Stack(const Stack& the_stack);
	// Destructor, destroy the stack and return memory allocated
	~Stack();

	// == Basic Operations ==
	// Purpose: Add new_number into the stack
	void push(double new_number);
	// Purpose: Remove and return the top number from the stack if not empty
	// Precondition: The stack is not empty
	double pop();

	// == Others ==
	// Purpose: Returns if the stack is empty
	bool empty() const;
};

#endif