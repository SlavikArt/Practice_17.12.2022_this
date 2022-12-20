#include "Hdd.h" // файл реализации
#include <iostream>
using namespace std;

Hdd::Hdd(const char* n, int m, double pr):memory(m), price(pr)
{
	if (name != nullptr)
	{
		delete[] name;
	}
	this->name = new char[strlen(n) + 1];
	strcpy_s(this->name, strlen(n) + 1, n);
}

Hdd::Hdd(const Hdd& h) :memory(h.memory),price(h.price)
{
	if (name != nullptr)
	{
		delete[] name;
	}
	this->name = new char[strlen(h.name) + 1];
	strcpy_s(this->name, strlen(h.name) + 1, h.name);
}

Hdd::~Hdd()
{
	delete[] name;
}

void Hdd::Input()
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

void Hdd::Print()
{
	cout << "-HDD-\n";
	cout << "Name: " << name
		<< "\nMemory: " << memory
		<< "\nPrice: " << price << "\n";
}

const char* Hdd::getName()
{
	return name;
}

const int Hdd::getMemory()
{
	return memory;
}

double Hdd::getPrice()
{
	return price;
}

void Hdd::setName(const char* n)
{
	if (name != nullptr)
	{
		delete[] name;
	}

	this->name = new char[strlen(n) + 1];
	strcpy_s(this->name, strlen(n) + 1, n);
}

void Hdd::setPrice(double pr)
{
	price = pr;
}
