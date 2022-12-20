#pragma once
class CP
{
	char* name;
	double Ghz;
	double price;
public:
	CP(const char* n, double g, double pr);
	CP(const CP& c);
	~CP();
	void Input();
	void Print();

	const char* getName();
	const int getGhz();
	double getPrice();

	void setName(const char* n);
	void setGhz(double g);
	void setPrice(double pr);
};

