//===========================================
// INTERFACE
//===========================================
// Course: CIS 054 (100616) C/C++ Programming
// Bonus Assignment: Lab Assignment 14-1 Exchange Data Function
// Name: Olga Sirenko
// ID: 0910134
// Date: 05/16/2020
// Platform:  Linux

#include <iostream>
#include <istream>
#include <cstdlib>
using namespace std;

// ============================== NODE =======================================
#ifndef NODE_H
#define NODE_H
struct Node
{
	// any type of data
	int data;
	Node *next;
};
typedef Node *NodePointer;

// Purpose: insert a new node at the head of list, with data = data
// Precondition: head is pointing to an existing linked list
void head_insert(NodePointer &head, int new_data);
// Purpose: remove all the nodes
void delete_nodes(NodePointer &head);
// Purpose: remove nodes with data = data, returns true if successful
void print_nodes(NodePointer head);
// Purpose: exchange head node data with tail node data
void exchange_data(NodePointer head);

#endif /*NODE_H*/
