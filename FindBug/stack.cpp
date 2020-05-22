// File: 	stack.h
// Purpose:	Implementation file for the class Stack of double number
// Author:	Monza Lui
// Date:	Nov 30, 2019
#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

Stack::Stack() : top(nullptr) {
	// intentionally doing nothing
}

Stack::Stack(const Stack& the_stack) {
	// similar to void insert(NodePointer after_me, int new_data);
	if (the_stack.empty()) {
		top = nullptr;
	} else {	// use else here because return doesn't look right
		NodePointer insert = new Node;
		top = insert;
		insert->number = the_stack.top->number;
		for (NodePointer iter = the_stack.top->next; iter != nullptr; iter = iter->next) {
				insert->next = new Node;
				insert = insert->next;
				insert->number = iter->number;
		}
		insert->next = nullptr;
	}
}

Stack::~Stack() {
	// similar to delete_all
	//cout << "Beginning of Destructor\n";
	NodePointer discard = top;
	while (discard != nullptr) {
		// 3. Set head to discard->next
		top = discard->next;
		cout << discard->number << " is being destroyed\n";
		// 4. Delete discard
		delete discard;
		// 5. Repeat from step 2
		discard = top;
	}
}

void Stack::push(double new_number) {
	// similar to head_insert
	NodePointer insert = new Node;
	insert->number = new_number;
	insert->next = top;
	top = insert;
}

double Stack::pop() {
	try {
		if (empty()) {
			throw 0;
		}
		// same as delete_all (but delete just one)
		NodePointer discard = top;
		double c = top->number;
		top = discard->next;
		delete discard;
		return c;
	} catch (int e) {
		cout << "pop() is not allowed when " 
		     << e << " elements in stack\n";
		exit(1);
	}

}

bool Stack::empty() const {
	return (top == nullptr);
}

ostream& operator << (ostream& outs, const Stack& the_stack) {
	NodePointer print = the_stack.top;
	while (print != nullptr) {
		outs << print->number << " ";
		print = print->next;
	}
	return outs;
}