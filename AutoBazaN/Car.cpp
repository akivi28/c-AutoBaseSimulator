#include "Car.h"

Car::Car() : name{0},state{0},carruing{0}
{
}

Car::Car(const Car& source)
{
	this->carruing = source.carruing;
	this->name = source.name;
	this->state = source.state;
}

Car& Car::operator=(const Car& source)
{
	this->carruing = source.carruing;
	this->name = source.name;
	this->state = source.state;
	return *this;
}

void Car::SetState(const string& state)
{
	this->state = state;
}

void Car::Init()
{
	for (int i = 0; i < 10; i++)
	{
		if (i < 2 || i > 7)
		{
			name += 'A' + rand() % ('Z' - 'A');
		}
		if (i == 2 || i == 7)
		{
			name += '_';
		}
		if (i > 2 && i < 7)
		{
			name += '1' + rand() % ('9' - '1');
		}
	}
	state = "free";
	carruing = 1 + rand() % 20;
}

void Car::Print()
{
	//cout << "************************************" << endl;
	cout << name << " carruing : " << carruing << " T, state : " << state << endl;
}

