// File:	linkedlist.cpp
// Lab:		Bonus Assignment: Lab Assignment 14-2 Reversing Linked List
// Purpose:	Implementation of the reverse function as described below.
//			You are to submit this file and linkedlist.h only.
// Reverse function:
// 		Write a void function that takes a linked list of integers and reverses the order
// 		of its nodes. The function will have one call-by-reference parameter that is a
// 		pointer to the head of the list. After the function is called, this pointer will
// 		point to the head of a linked list that has the same nodes as the original list, but
// 		in the reverse of the order they had in the original list.
// 		Note that your function will neither create nor destroy any nodes. It will simply
// 		rearrange nodes. Place your function in a suitable test program.
// Author:	Monza Lui
// Date:	Nov 26, 2019
#include <iostream>
#include "linkedlist.h"
#include "node.h"

using namespace std;

// This function inserts a new node onto the head of the list
// and is a class-based version of the same function defined
// in Display 15.4.
void head_insert(NodePtr &head, int the_number)
{
	NodePtr temp_ptr;
	temp_ptr = new Node(the_number, head);
	head = temp_ptr;
}
// go through the list with 3 nodes previous, current and next to keep pointers
// reasing link by the way of moving into reverse order
void reverse(NodePtr &head)
{

	Node *current = head; //assign the current to head
	Node *previous = NULL;
	Node *next = NULL;

	while (current != NULL) // continue untill the current is hit the end
	{
		next = current->getLink();	//assign current pointer to next
		current->setLink(previous); //assign previous pointer to current
		previous = current;
		current = next;
	}
	head = previous; //when the end is reached assign last
}

void print_nodes(NodePtr head)
{
	cout << "Current linked list: ";
	for (NodePtr iter = head; iter != nullptr; iter = iter->getLink())
	{
		cout << iter->getData() << " ";
	}
	cout << endl;
}

void delete_nodes(NodePtr &head)
{
	while (head != NULL)
	{
		NodePtr discard = head;
		head = head->getLink();
		cout << "Deleting " << discard->getData() << endl;
		delete discard;
	}
}