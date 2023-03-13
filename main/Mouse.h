#pragma once
class Mouse
{
	char* name;
	char* type;
	bool isWireless;
	char* color;
	double price;

	Mouse(bool isw);
	Mouse(bool isw, double pr);

public:
	Mouse();
	Mouse(const char* n, const char* t, bool isw, const char* col, double pr);
	Mouse(const Mouse& ms);
	~Mouse();
	
	void Input();
	void Print(bool inner);

	const char* getName()const;
	const char* getType()const;
	bool getIsWireless()const;
	const char* getColor()const;
	double getPrice()const;

	void setName(const char* n);
	void setType(const char* t);
	void setIsWireless(bool isw);
	void setColor(const char* col);
	void setPrice(double pr);

	Mouse& operator=(const Mouse& ms);
};
