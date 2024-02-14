#pragma once
#ifndef REQUEST_H
#define REQUEST_H

#include<iostream>
#include<string>
#include"Car.h"
#include"Driver.h"
#include"Goods.h"

enum Cities
{
	Lviv = 10,
	Ternopil = 15,
	Vinnica = 20,
	Kyiv = 25,
	Kherson = 30,
	Kharkiv = 35,
	Melitopol = 40,
	Mariupol = 45
};

using namespace std;
class Request
{
private:
	Car* carForRequest;
	Driver* driverForRequest;
	Goods goodsForRequest;
	int time;
	int arrivalTime;
	string place;
public:
	Request();
	
	void Generate();
	Goods& GetGood() { return goodsForRequest; }
	void InitDriver(Driver& sourceDriver);
	void InitCar(Car& sourceCar);
	void ClearDriver();
	void ClearCar();
	void Print();
	void SetArrivalTime(int globalTime);
	int GetArrivalTime();
	void RequestArrive();
	Driver& GetDriver() { return *driverForRequest; }
	Car& GetCar() { return *carForRequest; }

};

#endif 
