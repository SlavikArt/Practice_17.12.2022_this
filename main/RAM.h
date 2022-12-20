#pragma once
class RAM
{
	char* name;
	const int memory;
	double price;
public:
	RAM(const char* n, int m, double pr);
	RAM(const RAM& r);
	~RAM();
	void Input();
	void Print();

	const char* getName();
	const int getMemory();
	double getPrice();

	void setName(const char* n);
	void setPrice(double pr);
};

