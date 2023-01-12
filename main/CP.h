#pragma once
class CP
{
	char* name;
	double Ghz;
	double price;

	CP(int pr);
	CP(int g, double pr);

public:
	CP();
	CP(const char* n, double g, double pr);
	CP(const CP& c);
	~CP();
	void Input();
	void Print();

	const char* getName()const;
	const int getGhz()const;
	double getPrice()const;

	void setName(const char* n);
	void setGhz(double g);
	void setPrice(double pr);
};

