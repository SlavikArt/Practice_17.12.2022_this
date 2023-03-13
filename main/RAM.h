#pragma once
class RAM
{
	char* name;
	const int memory;
	double price;

	RAM(int m);
	RAM(int m, double pr);

public:
	RAM();
	RAM(const char* n, int m, double pr);
	RAM(const RAM& r);
	~RAM();
	void Input();
	void Print(bool inner);

	const char* getName()const;
	const int getMemory()const;
	double getPrice()const;

	void setName(const char* n);
	void setPrice(double pr);
};

