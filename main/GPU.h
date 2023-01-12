#pragma once
class GPU
{
	char* name;
	const int memory;
	double price;

	GPU(int m);
	GPU(int m, double pr);

public:
	GPU();
	GPU(const char* n, int m, double pr);
	GPU(const GPU& g);
	~GPU();
	void Input();
	void Print();

	const char* getName()const;
	const int getMemory()const;
	double getPrice()const;

	void setName(const char* n);
	void setPrice(double pr);
};

