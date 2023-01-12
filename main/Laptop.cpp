#include "Laptop.h"
#include <iostream>
using namespace std;

Laptop::Laptop()
{
	name = nullptr;
	price = 0;
}

Laptop::Laptop(const char* n, Hdd& h, GPU& g, CP& c, RAM& r, double pr)
	:hdd(h), gpu(g), cp(c), ram(r), price(pr)
{
	if (name != nullptr)
	{
		delete[] name;
	}
	this->name = new char[strlen(n) + 1];
	strcpy_s(this->name, strlen(n) + 1, n);
}

Laptop::Laptop(const Laptop& l) 
	:hdd(l.hdd), gpu(l.gpu), cp(l.cp), ram(l.ram), price(l.price)
{
	if (name != nullptr)
	{
		delete[] name;
	}
	this->name = new char[strlen(l.name) + 1];
	strcpy_s(this->name, strlen(l.name) + 1, l.name);
}

Laptop::~Laptop()
{
	delete[] name;
}

void Laptop::Input()
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

	hdd.Input();
	gpu.Input();
	cp.Input();
	ram.Input();

	cout << "Enter price -> ";
	cin >> price;
}

void Laptop::Print()
{
	cout << "-Laptop-\n";
	cout << "Name: " << name << "\n";
	cout << "Price: " << price << "\n";

	hdd.Print();
	gpu.Print();
	cp.Print();
	ram.Print();
}

const char* Laptop::getName()const
{
	return name;
}

Hdd Laptop::getHDD()const
{
	return hdd;
}

GPU Laptop::getGPU()const
{
	return gpu;
}

CP Laptop::getCP()const
{
	return cp;
}

RAM Laptop::getRAM()const
{
	return ram;
}

double Laptop::getPrice()const
{
	return price;
}

void Laptop::setName(const char* n)
{
	if (name != nullptr)
	{
		delete[] name;
	}
	this->name = new char[strlen(n) + 1];
	strcpy_s(this->name, strlen(n) + 1, n);
}

void Laptop::setHDD(Hdd& h)
{
	this->hdd.setName(h.getName());
	this->hdd.setPrice(h.getPrice());
}

void Laptop::setGPU(GPU& g)
{
	this->gpu.setName(g.getName());
	this->gpu.setPrice(g.getPrice());
}

void Laptop::setCP(CP& c)
{
	this->cp.setName(c.getName());
	this->cp.setGhz(c.getGhz());
	this->cp.setPrice(c.getPrice());
}

void Laptop::setRAM(RAM& r)
{	
	this->ram.setName(r.getName());
	this->ram.setPrice(r.getPrice());
}

void Laptop::setPrice(double pr)
{
	price = pr;
}
