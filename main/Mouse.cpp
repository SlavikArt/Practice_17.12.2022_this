#include "Mouse.h"
#include <iostream>
using namespace std;

Mouse::Mouse(bool isw)
{
    isWireless = isw;
}

Mouse::Mouse(bool isw, double pr)
    : Mouse(isw)
{
    price = pr;
}

Mouse::Mouse()
{
    name = nullptr;
    type = nullptr;
    isWireless = false;
    color = nullptr;
    price = 0;
}

Mouse::Mouse(const char* n, const char* t, bool isw, const char* col, double pr) 
    : Mouse(isw, pr)
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

Mouse::Mouse(const Mouse& ms)
    : isWireless(ms.isWireless), price(ms.price)
{
    if (name != nullptr)
        delete[] name;
    if (type != nullptr)
        delete[] type;
    if (color != nullptr)
        delete[] color;

    int len = strlen(ms.name) + 1;
    name = new char[len];
    strcpy_s(name, len, ms.name);

    len = strlen(ms.type) + 1;
    type = new char[len];
    strcpy_s(type, len, ms.type);

    len = strlen(ms.color) + 1;
    color = new char[len];
    strcpy_s(color, len, ms.color);
}

Mouse::~Mouse()
{
    delete[] name;
    delete[] type;
    delete[] color;
}

void Mouse::Input()
{
    char buf[100];

    cout << "Enter name -> ";
    cin.getline(buf, 100);
    setName(buf);

    cout << "Enter type -> ";
    cin.getline(buf, 100);
    setType(buf);

    cout << "Is it wireless -> ";
    cin >> boolalpha >> isWireless;
    cin.ignore();

    cout << "Enter color -> ";
    cin.getline(buf, 100);
    setColor(buf);

    cout << "Enter price -> ";
    cin >> price;
    cin.ignore();
}

void Mouse::Print(bool inner = false)
{
    if (!inner)
    {
        cout << "-Mouse-\n";
        cout << "Name: " << name << "\n";
        cout << "Type: " << type << "\n";
        cout << boolalpha << "Is wireless: " << isWireless << "\n";
        cout << "Color: " << color << "\n";
        cout << "Price: " << price << "\n";
    }
    else
    {
        cout << "  " << "-Mouse-\n";
        cout << "    " << "Name: " << name << "\n";
        cout << "    " << "Type: " << type << "\n";
        cout << "    " << boolalpha << "Is wireless: " << isWireless << "\n";
        cout << "    " << "Color: " << color << "\n";
        cout << "    " << "Price: " << price << "\n";
    }
}

const char* Mouse::getName()const
{
    return name;
}

const char* Mouse::getType()const
{
    return type;
}

bool Mouse::getIsWireless()const
{
    return isWireless;
}

const char* Mouse::getColor()const
{
    return color;
}

double Mouse::getPrice()const
{
    return price;
}

void Mouse::setName(const char* n)
{
    if (name != nullptr)
        delete[] name;

    int len = strlen(n) + 1;
    name = new char[len];
    strcpy_s(name, len, n);
}

void Mouse::setType(const char* t)
{
    if (type != nullptr)
        delete[] type;

    int len = strlen(t) + 1;
    type = new char[len];
    strcpy_s(type, len, t);
}

void Mouse::setIsWireless(bool isw)
{
    isWireless = isw;
}

void Mouse::setColor(const char* col)
{
    if (color != nullptr)
        delete[] color;

    int len = strlen(col) + 1;
    color = new char[len];
    strcpy_s(color, len, col);
}

void Mouse::setPrice(double pr)
{
    price = pr;
}

Mouse& Mouse::operator = (const Mouse& ms)
{
    if (&ms != this)
    {
        if (name != nullptr)
            delete[] name;
        if (type != nullptr)
            delete[] type;
        if (color != nullptr)
            delete[] color;

        int len = strlen(ms.name) + 1;
        name = new char[len];
        strcpy_s(name, len, ms.name);

        len = strlen(ms.type) + 1;
        type = new char[len];
        strcpy_s(type, len, ms.type);

        len = strlen(ms.color) + 1;
        color = new char[len];
        strcpy_s(color, len, ms.color);

        isWireless = ms.isWireless;
        price = ms.price;
    }
    return *this;
}
