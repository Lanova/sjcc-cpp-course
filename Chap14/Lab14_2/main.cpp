// File:	main.cpp
// Lab:		13-0 Bonuse lab 
// Purpose:	Test whether the reverse function described below works
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
#include "node.h"
#include "linkedlist.h"

using namespace std;

int main()
{
	NodePtr head;

	// Create a list of nodes 4->3->2->1->0
	head = new Node(0, NULL);
	for (int i=1; i<5; i++)
	{
		head_insert(head, i);
	}
	cout << "Just finished adding nodes\n";
	print_nodes(head);
	reverse(head);
	cout << "Just finished reversing the linked list\n";
	print_nodes(head);

	delete_nodes(head);
	return 0;
}
