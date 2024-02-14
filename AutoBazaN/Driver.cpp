#include "Driver.h"

string Driver::names[8]{ "Alexey","Danil","Oleg","Sregey","Petr","Pavel","Ivan","Artur" };

Driver::Driver() : name{0},state{0},expirience{0},salary{0}
{
}

Driver::Driver(const Driver& source)
{
	this->name = source.name;
	this->state = source.state;
	this->expirience = source.expirience;
	this->salary = source.salary;
}

Driver& Driver::operator=(const Driver& source)
{
	this->name = source.name;
	this->state = source.state;
	this->expirience = source.expirience;
	this->salary = source.salary;
	return *this;
}

void Driver::SetState(const string& stat)
{
	this->state = stat;
}

void Driver::SetSalary(const int sal)
{
	this->salary = sal;
}

void Driver::Init()
{
	
	name = names[rand() % 8];
	state = "free";
	expirience = 1 + rand() % 15;
	salary = 0;
}

bool Driver::TripReport()
{
	int random = rand() % 5;
	if (random == 5)
	{
		cout << "!!! the car broke down on the way, it needs to be repaired" << endl;
		return false;
	}
	else
	{
		cout << "the order is completed" << endl;
		return true;
	}
}

void Driver::Print()
{
	//cout << "------------------------------------" << endl;
	cout << name << ": " <<expirience << " y.of exp; sal: " << salary << " $ state : " << state << endl;
}


