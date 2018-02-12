#include "SimpleString.h"


// blank constructor 
SimpleString::SimpleString()
{
	numofCharacters = 0;
	characters = nullptr;

}

// is equal
bool SimpleString::isEqual(const SimpleString &d)
{
	// check to see if length is the same
	if (this->numofCharacters != d.numofCharacters)
	{
		return false;
	}
	// loop through both character arrays and compare index
	else
	{
		for (int i = 0; i < this->numofCharacters-1; i++)
		{
			if (this->characters[i] != d.characters[i])
			{
				return false;
			}
		}

		// all characters match
		return true;
	}
}


// destructor
SimpleString::~SimpleString()
{
	characters = NULL;
	numofCharacters = NULL;
}