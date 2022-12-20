#include "GPU.h"
#include <iostream>
using namespace std;

GPU::GPU(const char* n, int m, double pr):memory(m), price(pr)
{
	if (name != nullptr)
	{
		delete[] name;
	}
	this->name = new char[strlen(n) + 1];
	strcpy_s(this->name, strlen(n) + 1, n);
}

GPU::GPU(const GPU& g) :memory(g.memory), price(g.price)
{
	if (name != nullptr)
	{
		delete[] name;
	}
	this->name = new char[strlen(g.name) + 1];
	strcpy_s(this->name, strlen(g.name) + 1, g.name);
}

GPU::~GPU()
{
	delete[] name;
}

void GPU::Input()
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

void GPU::Print()
{
	cout << "-GPU-\n";
	cout << "Name: " << name
		<< "\nMemory: " << memory
		<< "\nPrice: " << price << "\n";
}

const char* GPU::getName()
{
	return name;
}

const int GPU::getMemory()
{
	return memory;
}

double GPU::getPrice()
{
	return price;
}

void GPU::setName(const char* n)
{
	if (name != nullptr)
	{
		delete[] name;
	}

	this->name = new char[strlen(n) + 1];
	strcpy_s(this->name, strlen(n) + 1, n);
}

void GPU::setPrice(double pr)
{
	price = pr;
}