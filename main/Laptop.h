#pragma once

#include "Hdd.h"
#include "GPU.h"
#include "CP.h"
#include "RAM.h"

#include "Mouse.h"
#include "WebCamera.h"
#include "Printer.h"

class Laptop
{
	char* name;
	Hdd hdd; // автоматически вызывается конструктор
	GPU gpu;
	CP cp;
	RAM ram;
	double price;

	Mouse* mss = nullptr;
	int mssCnt;
	WebCamera* wcams = nullptr;
	int wcamsCnt;
	Printer* prnts = nullptr;
	int prntsCnt;

public:
	Laptop();
	Laptop(const char* n, Hdd& h, GPU& g, CP& c, RAM& r, double pr);
	Laptop(const Laptop& l);
	~Laptop();

	Laptop(const char* n, Hdd& h, GPU& g, CP& c, RAM& r, double pr, 
		Mouse* m, int mCnt); // Mouse
	Laptop(const char* n, Hdd& h, GPU& g, CP& c, RAM& r, double pr,
		WebCamera* wc, int wcCnt); // WebCamera
	Laptop(const char* n, Hdd& h, GPU& g, CP& c, RAM& r, double pr,
		Printer* prt, int prtCnt); // Printer

	Laptop(const char* n, Hdd& h, GPU& g, CP& c, RAM& r, double pr, 
		Mouse* m, int mCnt, WebCamera* wc, int wcCnt); // Mouse + WebCamera
	Laptop(const char* n, Hdd& h, GPU& g, CP& c, RAM& r, double pr,
		Mouse* m, int mCnt, Printer* prt, int prtCnt); // Mouse + Printer
	Laptop(const char* n, Hdd& h, GPU& g, CP& c, RAM& r, double pr,
		WebCamera* wc, int wcCnt, Printer* prt, int prtCnt); // WebCamera + Printer
	Laptop(const char* n, Hdd& h, GPU& g, CP& c, RAM& r, double pr,
		Mouse* m, int mCnt, Printer* prt, int prtCnt, WebCamera* wc, int wcCnt); //Mouse + Printer + WebCamera
	
	void Input();
	void Print();

	const char* getName()const;
	Hdd getHDD()const;
	GPU getGPU()const;
	CP getCP()const;
	RAM getRAM()const;
	double getPrice()const;

	Mouse* getMouses()const;
	WebCamera* getWebCameras()const;
	Printer* getPrinters()const;
	
	void setName(const char* n);
	void setHDD(Hdd& h);
	void setGPU(GPU& g);
	void setCP(CP& c);
	void setRAM(RAM& r);
	void setPrice(double pr);

	void setMouses(Mouse* m, int mCnt);
	void setWebCameras(WebCamera* wc, int wcCnt);
	void setPrinters(Printer* prt, int prtCnt);
};
