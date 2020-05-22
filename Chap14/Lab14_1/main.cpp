// File:	main.cpp
// Lab:		13-1 lab exchange data function. See lab description for more details
// Purpose:	Test whether the exchange data function described below works
// Your task:	Define and implement the following function
// Exchange data function:
// 		Write a void function that takes a linked list of integers and
//		interchanges data in the first node with that in the last node.
//		The function will take a pointer to the head of the list. After the
//		function is called, it will retrieve data stored in it, then find and
//		retrieve data stored in the last node. The function will then interchange
//	 	the data of the first node with that of the last node.
//		Note that your function will neither create nor destroy any nodes. It will
//		simply interchange the data stored between the head and tail nodes. Place
// 		your function in a suitable test program.
// Author:	Monza Lui
// Date:	May 16, 2020

#include <iostream>
#include "node.h"
using namespace std;

int main()
{

	NodePointer head = nullptr;
	head_insert(head, 9);
	head_insert(head, 8);
	head_insert(head, 4);
	head_insert(head, 5);
	head_insert(head, 7);

	cout << "Just finished adding nodes\n";
	print_nodes(head);
	exchange_data(head);
	cout << "Just finished exchanging data\n";
	print_nodes(head);
	delete_nodes(head);

	return 0;
}
