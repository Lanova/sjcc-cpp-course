//===========================================
// IMPLEMENTATION
//===========================================
// Course: CIS 054 (100616) C/C++ Programming
// Bonus Assignment: Lab Assignment 14-1 Exchange Data Function
// Name: Olga Sirenko
// ID: 0910134
// Date: 05/16/2020
// Platform:  Linux
// ===========================================

#include <iostream>
#include <ostream>
#include "node.h"
using namespace std;

void head_insert(NodePointer &head, int new_data)
{
	// Create a new NodePointer temp_pointer
	// Create a new Node
	NodePointer temp_pointer = new Node;

	// Set the new Node’s data to 9
	temp_pointer->data = new_data;
	// Set the new Node’s pointer next to equal to head
	temp_pointer->next = head;
	// Set head to equal to temp_pointer
	head = temp_pointer;
	// Set temp_pointer to nullptr
	temp_pointer = nullptr;
}

void delete_nodes(NodePointer &head)
{
	NodePointer iter = head, iter2;
	//for (iter = head; iter != nullptr; iter = iter->next)
	while (iter != nullptr)
	{
		iter2 = iter->next;
		// iter pointing to the node that we are deleting
		// iter2 pointing to the node after the one iter is pointing to
		cout << iter->data << " is being destroyed\n";
		delete iter;
		iter = iter2;
	}
	head = nullptr;
}
// cout nodes value one by one
void print_nodes(NodePointer head)
{
	cout << "Current linked list: ";
	for (NodePointer iter = head; iter != nullptr; iter = iter->next)
	{
		cout << " " << iter->data;
	}
	cout << endl;
}
// Purpose: exchange head node data with tail node data
void exchange_data(NodePointer head)
{
	int tail_data;

	NodePointer iter = head, iter2;
	for (iter = head; iter != nullptr; iter = iter->next) //iterating to find a tail
	{
		if (iter->next == nullptr) //when the tail is found
		{
			tail_data = iter->data;	 //store tail data into temp variable
			iter->data = head->data; //assigne head data into tail value
			head->data = tail_data;	 //asign temp stored tail data into head node value
		}
	}
}