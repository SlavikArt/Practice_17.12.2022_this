#pragma once

#include "Hdd.h"
#include "GPU.h"
#include "CP.h"
#include "RAM.h"

class Laptop
{
	char* name;
	Hdd hdd; // автоматически вызывается конструктор
	GPU gpu;
	CP cp;
	RAM ram;
	double price;
public:
	Laptop();
	Laptop(const char* n, Hdd& h, GPU& g, CP& c, RAM& r, double pr);
	Laptop(const Laptop& l);
	~Laptop();
	void Input();
	void Print();

	const char* getName()const;
	Hdd getHDD()const;
	GPU getGPU()const;
	CP getCP()const;
	RAM getRAM()const;
	double getPrice()const;

	void setName(const char* n);
	void setHDD(Hdd& h);
	void setGPU(GPU& g);
	void setCP(CP& c);
	void setRAM(RAM& r);
	void setPrice(double pr);
};

