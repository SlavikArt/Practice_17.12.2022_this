#pragma once // файл дизайна
class Hdd
{
	char* name;
	const int memory;
	double price;
public:
	Hdd(const char* n, int m, double pr);
	Hdd(const Hdd& h);
	~Hdd();
	void Input();
	void Print();

	// get
	const char* getName();
	const int getMemory();
	double getPrice();

	// set
	void setName(const char* n);
	void setPrice(double pr);
};

