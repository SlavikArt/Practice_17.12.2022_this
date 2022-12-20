#include "Laptop.h"

int main()
{
    Hdd h("Kingsman", 1000, 2500);
    GPU g("NVIDIA RTX 3080", 8192, 20000);
    CP c("Intel core I5", 3.5, 13000);
    RAM r("Asus", 32768, 6000);

    Laptop obj1("Asus", h, g, c, r, 32500);
    obj1.Print();
}