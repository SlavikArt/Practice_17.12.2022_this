#include "Laptop.h"
#include <iostream>
using namespace std;

int main()
{
    Hdd hdd("Kingsman", 1000, 2500);
    GPU gpu("NVIDIA RTX 3080", 8192, 20000);
    CP cp("Intel core I5", 3.5, 13000);
    RAM ram("Asus", 32768, 6000);

    Laptop obj1(
        "Asus",
        hdd, 
        gpu, 
        cp, 
        ram, 
        32500
    );
    obj1.Print();

    cout << "\n";

    Mouse* mouses = new Mouse[1];
    mouses[0] = Mouse("Logitech", "Gaming", true, "Black", 1000.0);

    WebCamera* webCameras = new WebCamera[1];
    webCameras[0] = WebCamera("Logitech", "1980x1080", true, "Gray", 2000.0);

    Printer* printers = new Printer[2];
    printers[0] = Printer("Canon", "Laser", false, "Blue", 5000.0);
    printers[1] = Printer("Xerox", "Inkjet", true, "Gray", 3800.0);

    Laptop obj2(
        "Lenovo",
        hdd,
        gpu,
        cp,
        ram,
        50300,
        mouses, 1,
        printers, 2,
        webCameras, 1
    );
    obj2.Print();

    delete[] mouses;
    delete[] webCameras;
    delete[] printers;
}
