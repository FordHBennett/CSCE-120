#include <iostream>
#include <string>
#include "Node.h"
#include "TemperatureData.h"

using namespace std;

// Default constructor
Node::Node():data(), next(nullptr)
{
	data = TemperatureData();
} // remember to initialize next to nullptr

// Parameterized constructor
Node::Node(string id, int year, int month, double temperature):data(),next(nullptr)
{
	data = TemperatureData(id, year, month, temperature);
}
// remember to initialize next to nullptr

bool Node::operator<(const Node& b) {
	if (this->data.id < b.data.id)
	{
		return true;
	}
	else if(this->data.id > b.data.id)
	{
		return false;
	}
	else
	{
		if(this->data.year < b.data.year)
		{
			return true;
		}
		else if (this->data.year > b.data.year)
		{
			return false;
		}
		else
		{
			if(this->data.month < b.data.month)
			{
				return true;
			}
			else if(this->data.month > b.data.month)
			{
				return false;
			}
		}

	}

	return true;
}
