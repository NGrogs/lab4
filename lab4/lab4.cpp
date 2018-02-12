// lab4.cpp : Defines the entry point for the console application.
//

#include "List.h"
#include "Node.h"
#include "SimpleString.h"


int main()
{
	
	// create simple strings 
	SimpleString *word1 = new SimpleString(5, "Fast");
	SimpleString *word2 = new SimpleString(7, "Easter");
	SimpleString *word3 = new SimpleString(6, "Steam");
	SimpleString *word4 = new SimpleString(3, "Hi");
	SimpleString *word5 = new SimpleString(6, "Quick");
	SimpleString *word6 = new SimpleString(10, "Bamboozle");
	SimpleString *word7 = new SimpleString(4, "Mup");
	SimpleString *word8 = new SimpleString(4, "Zap");
	SimpleString *popWord1 = new SimpleString();
	SimpleString *popWord2 = new SimpleString();

	// address of a node
	Node *nextNode;

	// create a list
	List myList;

	// add the nodes to the list
	myList.push_front(*word1);
	myList.push_back(*word3);
	myList.push_front(*word4);

	// PRINT LIST
	myList.displayToConsole();
	
	
	system("pause");

	// search for the node in array to insert after 
	nextNode = myList.search(*word1);
	if (nextNode == nullptr)
	{
		cout << "Node not found" << endl;
	}
	else
	{
		myList.insertAfter(nextNode, *word2); 
	}


	// PRINT LIST
	myList.displayToConsole();
	system("pause");

	// POP BACK 
	if (myList.pop_back(*popWord1) == true)
	{
		cout << "Value popped at front is " << popWord1->characters << endl;
	}
	else
	{
		cout << "Pop back unsuccessful" << endl;
	}


	// PRINT LIST
	myList.displayToConsole();
	system("pause");

	// POP FRONT
	if (myList.pop_front(*popWord2) == true)
	{
		cout << "Value popped at front is " << popWord2->characters << endl;
	}
	else
	{
		cout << "Pop back unsuccessful" << endl;
	}


	// PRINT LIST
	myList.displayToConsole();
	system("pause");

	nextNode = myList.search(*word2);
	if (nextNode != nullptr)
	{
		myList.erase(nextNode);
	}
	else
	{
		cout << "Node not found" << endl;
	}

	// PRINT LIST
	myList.displayToConsole();
	system("pause");

	//clean up 
	delete popWord1;
	delete popWord2;
	delete word1;
	delete word2;
	delete word3;
	delete word4;
	delete word5;
	delete word6;
	delete word7;
	delete word8;

	cout << "Memory cleared, bye." << endl;

    return 0;
}