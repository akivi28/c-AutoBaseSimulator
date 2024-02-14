#pragma once
#ifndef DRIVER_H
#define DRIVER_H

#include<iostream>
#include<string>

using namespace std;

class Driver
{
private:
	static string names[8];
	string name;
	string state;
	int expirience;
	double salary;
public:
	Driver();
	Driver(const Driver& source);

	Driver& operator =(const Driver& source);

	int GetExp() { return expirience; }
	string GetState() { return state; }
	int GetSalary() { return salary; }

	void SetState(const string& stat);
	void SetSalary(const int sal);

	void Init();
	bool TripReport();
	void Print();

};

#endif // !DRIVER_H


