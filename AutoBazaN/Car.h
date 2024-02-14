#pragma once

#ifndef CAR_H
#define CAR_H

#include<iostream>
#include <string>

using namespace std;
class Car
{
private:
	string name;
	string state;
	int carruing;
public:
	Car();
	Car(const Car& source);

	Car& operator =(const Car& source);

	string GetState() { return state; }
	int GetCarruing() { return carruing; }

	void SetState(const string& state);

	void Init();
	void Print();
};


#endif // 

