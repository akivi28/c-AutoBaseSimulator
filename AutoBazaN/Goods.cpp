#include "Goods.h"

string Goods::types[9]{ "clothes", "bed linen", "toys",
						"furniture", "food", "books",
						"medicines", "electronics", "glass" };

Goods::Goods() : type{0},state{0},weight{0}
{
}

Goods::Goods(const Goods& source)
{
	this->state = source.state;
	this->type = source.type;
	this->weight = source.weight;
}

Goods& Goods::operator=(const Goods& source)
{
	this->state = source.state;
	this->type = source.type;
	this->weight = source.weight;
	return *this;
}

void Goods::SetState(const string& stat)
{
	this->state = stat;
}

void Goods::Init()
{
	type = types[rand() % 9];
	weight = 1 + rand() % 20;
	state = "awaiting";
}

void Goods::Print()
{
	//cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	cout << type << ": " << weight << " T, state : " << state << endl;
}
