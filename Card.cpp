#include <iostream>
#include "Card.h"
using namespace std;

Card::Card(int tempVal)
{
	cardVal = tempVal;
}

int Card::getValue() const
{
	return cardVal;
}