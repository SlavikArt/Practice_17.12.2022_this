#pragma once // файл дизайна
class Hdd
{
	char* name;
	const int memory;
	double price;

	Hdd(int m);
	Hdd(int m, double pr);

public:
	Hdd();
	Hdd(const char* n, int m, double pr);
	Hdd(const Hdd& h);
	~Hdd();
	void Input();
	void Print(bool inner);

	// get
	const char* getName()const;
	const int getMemory()const;
	double getPrice()const;

	// set
	void setName(const char* n);
	void setPrice(double pr);
};

