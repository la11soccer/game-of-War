#pragma once
#include <iostream>
using namespace std;

class Card
{
public: 
	Card(int tempVal);

	int getValue() const;
private:
	int cardVal;
};