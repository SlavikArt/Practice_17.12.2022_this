#include "RAM.h"
#include <iostream>
using namespace std;

RAM::RAM(int m) :memory(m)
{

}

RAM::RAM(int m, double pr) :RAM(m)
{
	price = pr;
}

RAM::RAM() :memory(0)
{
	name = nullptr;
	price = 0;
}

RAM::RAM(const char* n, int m, double pr):RAM(m, pr)
{
	if (name != nullptr)
	{
		delete[] name;
	}
	this->name = new char[strlen(n) + 1];
	strcpy_s(this->name, strlen(n) + 1, n);
}

RAM::RAM(const RAM& r) :memory(r.memory), price(r.price)
{
	if (name != nullptr)
	{
		delete[] name;
	}
	this->name = new char[strlen(r.name) + 1];
	strcpy_s(this->name, strlen(r.name) + 1, r.name);
}

RAM::~RAM()
{
	delete[] name;
}

void RAM::Input()
{
	char buf[20];
	cout << "Enter name -> ";
	cin.getline(buf, 20);

	if (name != nullptr)
	{
		delete[] name;
	}

	this->name = new char[strlen(buf) + 1];
	strcpy_s(this->name, strlen(buf) + 1, buf);
	cout << "Enter price -> ";
	cin >> price;
}

void RAM::Print()
{
	cout << "-RAM-\n";
	cout << "Name: " << name
		<< "\nMemory: " << memory
		<< "\nPrice: " << price << "\n";
}

const char* RAM::getName()const
{
	return name;
}

const int RAM::getMemory()const
{
	return memory;
}

double RAM::getPrice()const
{
	return price;
}

void RAM::setName(const char* n)
{
	if (name != nullptr)
	{
		delete[] name;
	}

	this->name = new char[strlen(n) + 1];
	strcpy_s(this->name, strlen(n) + 1, n);
}

void RAM::setPrice(double pr)
{
	price = pr;
}
