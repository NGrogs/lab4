#pragma once
#include "SimpleString.h"
using namespace std;

class Node
{
public:
	SimpleString *data;
	Node *next;
	Node(const SimpleString &d, Node *n = 0);
	~Node();
};	