#include "List.h"


// constructor
List::List()
{
	head = nullptr;
	cout << "List created" << endl;
}

// insert before 
void List::insertBefore(Node *loc, const SimpleString &d)
{
	if (head == nullptr)
	{
		//set head to point to new node
		Node *newnode = new Node(d, nullptr);
		head = newnode;
	}
	else
	{
		// loop until current->next == *loc
		Node *current = head;
		Node *newNode = new Node(d,0);
		while (current->next != loc)
		{
			current = current->next;
		}

		// insert new node after current (between current and the chosen node)
		newNode->next = current->next;
		current->next = newNode;
		
	}

	cout << "1 node inserted before (" << d.characters << ")" << endl;
}

// insert after
void List::insertAfter(Node *loc, const SimpleString &d)
{
	if (head == nullptr)
	{
		Node *newnode = new Node(d, nullptr);
		head = newnode;
	}
	else
	{
		// loop until current == loc
		Node *current = head;
		Node *newNode = new Node(d, 0);
		while (current != loc)
		{
			current = current->next;
		}

		// insert new node after current 
		newNode->next = current->next;
		current->next = newNode;

		
		
	}
	cout << "1 node inserted after (" << d.characters << ")" << endl;
}

// push to back
void List::push_back(const SimpleString &d)
{
	if (head == nullptr)
	{
		Node *newnode = new Node(d, nullptr);
		head = newnode;
	}
	else
	{
		Node *current = head;
		Node *newNode = new Node(d, 0);
		while (current->next != nullptr)
		{
			current = current->next;
		}

		// insert new node after current 
		newNode->next = nullptr;
		current->next = newNode;

	}
	cout << "1 node pushed to back (" << d.characters << ")" << endl;
}

// push to front
void List::push_front(const SimpleString &d)
{
	if (head == nullptr)
	{
		Node *newNode = new Node(d, nullptr);
		head = newNode;
	}
	else
	{
		//go to head
		Node *current = head;
		Node *newNode = new Node(d, 0);

		newNode->next = head;
		head = newNode;

		
	}
	cout << "1 node pushed to front (" << d.characters << ")"<< endl;
}

// pop last element
bool List::pop_back(SimpleString &d)
{
	//if list empty
	if (head == nullptr)
	{
		return false;
	}
	
	// if list not empty
	else
	{
		// travel to 2nd last node
		Node *current = head;
		Node *temp;
		while (current->next->next != nullptr)
		{
			current = current->next;
		}

		temp = current->next;
		// get the data from last node
		d.characters = current->next->data->characters; // PROBLEM

		// remove node and adjust list
		current->next = nullptr;

		// delete old node
		delete temp;

		return true;
	}
}

// pop first element
bool List::pop_front(SimpleString &d)
{
	// if list empty
	if (head == nullptr)
	{
		return false;
	}

	//if list not empty
	else
	{
		
		Node *temp = head;

		// get the data from head
		d.characters = head->data->characters;

		// remove node and adjust list
		head = head->next;

		//delete old node
		delete temp;

		return true;
	}
}

// delete a node
void List::erase(Node *loc)
{
	if (head == nullptr)
	{
		cout << "Cannot delete from empty node" << endl;
	}
	Node *current = head;

	//move to node before selected node
	while (current->next != loc)
	{
		current = current->next;
	}

	// get location of node to delete
	Node *temp = current->next;

	// adjust the list
	current->next = current->next->next;


	cout << "1 node deleted (" << temp->data->characters << ")"<< endl;
	// delete the node
	delete temp;
	
	

}

Node *List::search(const SimpleString &d)
{
	// if list empty
	if (head == nullptr)
	{
		return nullptr;
	}
	
	// if list not empty
	else
	{
		//start at head
		Node *current = head;

		// navigate until end of list
		while (current != nullptr)
		{
			//if strings are the same
			if (current->data->isEqual(d))
			{
				return current;
			}
			// if at end
			else if (current->next == nullptr)
			{
				return nullptr;
			}

			// move to next point
			current = current->next;
		}

	}



}

// destructor
List::~List()
{
	// loop through the list and call destructor for each node
	Node *current = head;
	Node *temp;
	while (current != nullptr)
	{
		temp = current;
		current = current->next;
		delete temp;
	}

}

void List::displayToConsole()
{
	Node *current = head;
	cout << endl;
	while (current != nullptr)
	{
		cout << current->data->characters << "->" ;
		current = current->next;
	}
	cout << endl;
}