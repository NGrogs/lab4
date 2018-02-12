#pragma once
#include <iostream>
using namespace std; 

class SimpleString
{
public:
	int numofCharacters;
	char  *characters;
	//create memory for characters and copy the str array 
	SimpleString(int t_numofCharacters, char str[]):numofCharacters(t_numofCharacters) {

		characters = new char[numofCharacters];
		for (int i = 0; i<numofCharacters - 1; i++)
		{
			characters[i] = str[i];
		}
		characters[numofCharacters - 1] = 0;
	};

	SimpleString();
	~SimpleString();

	bool isEqual(const SimpleString &d);

};
