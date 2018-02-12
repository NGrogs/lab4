#include "Node.h"

// constructor 
Node::Node(const SimpleString &d, Node *n)
{
	data = new SimpleString(d);
	next = n;
}

// destructor
Node::~Node()
{

	next = NULL;
	data = NULL;
}










