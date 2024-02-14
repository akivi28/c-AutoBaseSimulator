#pragma once
#ifndef CONTROLCENTR_H
#define CONTROLCENTR_H

#include"Request.h"
#include <conio.h>
#include <windows.h>
#include<vector>

using namespace std;

enum Direction { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, esc = 27 };
//HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

class —ontrol—enter
{
private:
	static int time;

	vector<Car> cars;
	vector<Driver> drivers;
	vector<Request> request;

	void AddDriver();
	void AddCar();
	void AddRequest();

	bool ComparisonByExperience(Goods& sourceGood,Driver&sourceDriver);

	void Menu(int numOfReq);
	void FillingRequest(int numOfReq);
	int Show();
	void Init();

	void AutoFillRequest(int numOfReq);

	bool AutoCompareDriver(Goods& sourceGood, Driver& sourceDriver);

	bool AutoCompareCar(Goods& sourceGood, Car& sourceCar);
public:

	—ontrol—enter();
	void Start();
	void StartSimulation();
	
};

#endif 


