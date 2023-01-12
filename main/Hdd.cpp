#include "Hdd.h" // файл реализации
#include <iostream>
using namespace std;

Hdd::Hdd(int m) :memory(m) 
{

}

Hdd::Hdd(int m, double pr):Hdd(m)
{
	price = pr;
}

Hdd::Hdd():memory(0)
{
	name = nullptr;
	price = 0;
}

Hdd::Hdd(const char* n, int m, double pr):Hdd(m, pr)
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

const char* Hdd::getName()const
{
	return name;
}

const int Hdd::getMemory()const
{
	return memory;
}

double Hdd::getPrice()const
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
