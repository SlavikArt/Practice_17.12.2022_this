#include "Printer.h"
#include <iostream>
using namespace std;

Printer::Printer(bool hs)
{
    hasScanner = hs;
}

Printer::Printer(bool hs, double pr)
    : Printer(hs)
{
    price = pr;
}

Printer::Printer()
{
    name = nullptr;
    type = nullptr;
    hasScanner = false;
    color = nullptr;
    price = 0;
}

Printer::Printer(const char* n, const char* t, bool hs, const char* col, double pr)
    : Printer(hs, pr)
{
    int len = strlen(n) + 1;
    name = new char[len];
    strcpy_s(name, len, n);

    len = strlen(t) + 1;
    type = new char[len];
    strcpy_s(type, len, t);

    len = strlen(col) + 1;
    color = new char[len];
    strcpy_s(color, len, col);
}

Printer::Printer(const Printer& prnt)
    : hasScanner(prnt.hasScanner), price(prnt.price)
{
    if (name != nullptr)
        delete[] name;
    if (type != nullptr)
        delete[] type;
    if (color != nullptr)
        delete[] color;

    int len = strlen(prnt.name) + 1;
    name = new char[len];
    strcpy_s(name, len, prnt.name);

    len = strlen(prnt.type) + 1;
    type = new char[len];
    strcpy_s(type, len, prnt.type);

    len = strlen(prnt.color) + 1;
    color = new char[len];
    strcpy_s(color, len, prnt.color);
}

Printer::~Printer()
{
    delete[] name;
    delete[] type;
    delete[] color;
}

void Printer::Input()
{
    char buf[100];

    cout << "Enter name -> ";
    cin.getline(buf, 100);
    setName(buf);

    cout << "Enter type -> ";
    cin.getline(buf, 100);
    setType(buf);

    cout << "Has scanner -> ";
    cin >> boolalpha >> hasScanner;
    cin.ignore();

    cout << "Enter color -> ";
    cin.getline(buf, 100);
    setColor(buf);

    cout << "Enter price -> ";
    cin >> price;
    cin.ignore();
}

void Printer::Print(bool inner = false)
{
    if (!inner)
    {
        cout << "-Printer-\n";
        cout << "Name: " << name << "\n";
        cout << "Type: " << type << "\n";
        cout << boolalpha << "Has scanner: " << hasScanner << "\n";
        cout << "Color: " << color << "\n";
        cout << "Price: " << price << "\n";
    }
    else
    {
        cout << "  " << "-Printer-\n";
        cout << "    " << "Name: " << name << "\n";
        cout << "    " << "Type: " << type << "\n";
        cout << "    " << boolalpha << "Has scanner: " << hasScanner << "\n";
        cout << "    " << "Color: " << color << "\n";
        cout << "    " << "Price: " << price << "\n";
    }
    
}

const char* Printer::getName() const
{
    return name;
}

const char* Printer::getType() const
{
    return type;
}

bool Printer::getHasScanner() const
{
    return hasScanner;
}

const char* Printer::getColor() const
{
    return color;
}

double Printer::getPrice() const
{
    return price;
}

void Printer::setName(const char* n)
{
    if (name != nullptr)
        delete[] name;

    int len = strlen(n) + 1;
    name = new char[len];
    strcpy_s(name, len, n);
}

void Printer::setType(const char* t)
{
    if (type != nullptr)
        delete[] type;

    int len = strlen(t) + 1;
    type = new char[len];
    strcpy_s(type, len, t);
}

void Printer::setHasScanner(bool hs)
{
    hasScanner = hs;
}

void Printer::setColor(const char* c)
{
    if (color != nullptr)
        delete[] color;

    int len = strlen(c) + 1;
    color = new char[len];
    strcpy_s(color, len, c);
}

void Printer::setPrice(double p)
{
    price = p;
}

Printer& Printer::operator=(const Printer& prnt)
{
    if (&prnt != this)
    {
        if (name != nullptr)
            delete[] name;
        if (type != nullptr)
            delete[] type;
        if (color != nullptr)
            delete[] color;

        int len = strlen(prnt.name) + 1;
        name = new char[len];
        strcpy_s(name, len, prnt.name);

        len = strlen(prnt.type) + 1;
        type = new char[len];
        strcpy_s(type, len, prnt.type);

        len = strlen(prnt.color) + 1;
        color = new char[len];
        strcpy_s(color, len, prnt.color);

        hasScanner = prnt.hasScanner;
        price = prnt.price;
    }
    return *this;
}
