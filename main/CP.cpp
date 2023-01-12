#include "CP.h"
#include <iostream>
using namespace std;

CP::CP(int pr)
{
	price = pr;
}

CP::CP(int g, double pr) :CP(pr)
{
	Ghz = g;
}

CP::CP()
{
	name = nullptr;
	Ghz = 0;
	price = 0;
}

CP::CP(const char* n, double g, double pr):CP(g, pr)
{
	if (name != nullptr)
	{
		delete[] name;
	}
	this->name = new char[strlen(n) + 1];
	strcpy_s(this->name, strlen(n) + 1, n);
}

CP::CP(const CP& c) :Ghz(c.Ghz), price(c.price)
{
	if (name != nullptr)
	{
		delete[] name;
	}
	this->name = new char[strlen(c.name) + 1];
	strcpy_s(this->name, strlen(c.name) + 1, c.name);
}

CP::~CP()
{
	delete[] name;
}

void CP::Input()
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
	cout << "Enter Ghz -> ";
	cin >> Ghz;
	cout << "Enter price -> ";
	cin >> price;
}

void CP::Print()
{
	cout << "-CP-\n";
	cout << "Name: " << name
		<< "\nGhz: " << Ghz
		<< "\nPrice: " << price << "\n";
}

const char* CP::getName()const
{
	return name;
}

const int CP::getGhz()const
{
	return Ghz;
}

double CP::getPrice()const
{
	return price;
}

void CP::setName(const char* n)
{
	if (name != nullptr)
	{
		delete[] name;
	}

	this->name = new char[strlen(n) + 1];
	strcpy_s(this->name, strlen(n) + 1, n);
}

void CP::setGhz(double g)
{
	Ghz = g;
}

void CP::setPrice(double pr)
{
	price = pr;
}
