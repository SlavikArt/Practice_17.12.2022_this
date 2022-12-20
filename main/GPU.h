#pragma once
class GPU
{
	char* name;
	const int memory;
	double price;
public:
	GPU(const char* n, int m, double pr);
	GPU(const GPU& g);
	~GPU();
	void Input();
	void Print();

	const char* getName();
	const int getMemory();
	double getPrice();

	void setName(const char* n);
	void setPrice(double pr);
};

