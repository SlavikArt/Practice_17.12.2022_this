#pragma once
class Printer
{
	char* name;
	char* type;
	bool hasScanner;
	char* color;
	double price;

    Printer(bool hs);
    Printer(bool hs, double pr);

public:
    Printer();
    Printer(const char* n, const char* t, bool hs, const char* col, double pr);
    Printer(const Printer& prnt);
    ~Printer();
    
    void Input();
    void Print(bool inner);

    const char* getName() const;
    const char* getType() const;
    bool getHasScanner() const;
    const char* getColor() const;
    double getPrice() const;

    void setName(const char* n);
    void setType(const char* t);
    void setHasScanner(bool hs);
    void setColor(const char* c);
    void setPrice(double p);

    Printer& operator=(const Printer& prnt);
};

