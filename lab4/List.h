#pragma once
#include "Node.h"
#include "SimpleString.h"
#include <iostream>
using namespace std; 


class List
{

	Node *head;

public:

	List();
	~List();
	// insert a copy of d
	void insertBefore(Node *loc, const SimpleString &d);
	void insertAfter(Node *loc, const SimpleString &d);
	//push a copy of d
	void push_back(const SimpleString &d);
	void push_front(const SimpleString &d);
	//retrurns true if  pop_back/pop_front successful and delete from memory.  d now has a copy of the contents of the popped element. 
	bool pop_back(SimpleString &d);
	bool pop_front(SimpleString &d);
	// erase the node and delete it from memory
	void erase(Node *loc);
	//return a pointer the searched node. If nullptr is returned then the node is not found
	Node *search(const SimpleString &d);

	//print list method
	void displayToConsole();

	void Print();
};
