#include "GPU.h"
#include <iostream>
using namespace std;

GPU::GPU(int m) :memory(m)
{

}

GPU::GPU(int m, double pr) :GPU(m)
{
	price = pr;
}

GPU::GPU() :memory(0)
{
	name = nullptr;
	price = 0;
}

GPU::GPU(const char* n, int m, double pr):GPU(m, pr)
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

const char* GPU::getName()const
{
	return name;
}

const int GPU::getMemory()const
{
	return memory;
}

double GPU::getPrice()const
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
