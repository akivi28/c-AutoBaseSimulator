#pragma once
#ifndef GOODS_H
#define GOODS_H

#include<iostream>
#include<string>

using namespace std;

class Goods
{
private:
	static string types[9];
	string type;
	string state;
	int weight;
public:
	Goods();
	Goods(const Goods& source);

	Goods& operator =(const Goods& source);

	string GetType() { return type; }
	int GetWeight() { return weight; }
	string GetState() { return state; }

	void SetState(const string& stat);

	void Init();
	void Print();
};

#endif 
