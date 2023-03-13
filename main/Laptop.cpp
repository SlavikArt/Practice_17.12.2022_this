#include "Laptop.h"
#include <iostream>
using namespace std;

Laptop::Laptop()
{
	name = nullptr;
	price = 0;
}

Laptop::Laptop(const char* n, Hdd& h, GPU& g, CP& c, RAM& r, double pr)
	:hdd(h), gpu(g), cp(c), ram(r), price(pr)
{
	if (name != nullptr)
	{
		delete[] name;
	}
	this->name = new char[strlen(n) + 1];
	strcpy_s(this->name, strlen(n) + 1, n);
}

Laptop::Laptop(const char* n, Hdd& h, GPU& g, CP& c, RAM& r, double pr, 
	Mouse* m, int mCnt) 
	: Laptop(n, h, g, c, r, pr) // Mouse
{
	setMouses(m, mCnt);
}

Laptop::Laptop(const char* n, Hdd& h, GPU& g, CP& c, RAM& r, double pr, 
	WebCamera* wc, int wcCnt)
	: Laptop(n, h, g, c, r, pr) // WebCamera
{
	setWebCameras(wc, wcCnt);
}

Laptop::Laptop(const char* n, Hdd& h, GPU& g, CP& c, RAM& r, double pr,
	Printer* prt, int prtCnt)
	: Laptop(n, h, g, c, r, pr) // Printer
{
	setPrinters(prt, prtCnt);
}

Laptop::Laptop(const char* n, Hdd& h, GPU& g, CP& c, RAM& r, double pr,
	Mouse* m, int mCnt, WebCamera* wc, int wcCnt) 
	: Laptop(n, h, g, c, r, pr) // Mouse + WebCamera
{
	setMouses(m, mCnt);
	setWebCameras(wc, wcCnt);
}

Laptop::Laptop(const char* n, Hdd& h, GPU& g, CP& c, RAM& r, double pr,
	Mouse* m, int mCnt, Printer* prt, int prtCnt)
	: Laptop(n, h, g, c, r, pr) // Mouse + Printer
{
	setMouses(m, mCnt);
	setPrinters(prt, prtCnt);
}

Laptop::Laptop(const char* n, Hdd& h, GPU& g, CP& c, RAM& r, double pr,
	WebCamera* wc, int wcCnt, Printer* prt, int prtCnt)
	: Laptop(n, h, g, c, r, pr) // WebCamera + Printer
{
	setWebCameras(wc, wcCnt);
	setPrinters(prt, prtCnt);
}

Laptop::Laptop(const char* n, Hdd& h, GPU& g, CP& c, RAM& r, double pr,
	Mouse* m, int mCnt, Printer* prt, int prtCnt, WebCamera* wc, int wcCnt)
	: Laptop(n, h, g, c, r, pr) // Mouse + Printer + WebCamera 
{
	setMouses(m, mCnt);
	setPrinters(prt, prtCnt);
	setWebCameras(wc, wcCnt);
}

Laptop::Laptop(const Laptop& l) 
	:hdd(l.hdd), gpu(l.gpu), cp(l.cp), ram(l.ram), price(l.price),
	mssCnt(l.mssCnt), wcamsCnt(l.wcamsCnt), prntsCnt(l.prntsCnt)
{
	if (name != nullptr)
		delete[] name;
	if (mss != nullptr)
		delete[] mss;
	if (wcams != nullptr)
		delete[] wcams;
	if (prnts != nullptr)
		delete[] prnts;

	setName(l.name);
	setMouses(l.mss, l.mssCnt);
	setWebCameras(l.wcams, l.wcamsCnt);
	setPrinters(l.prnts, l.prntsCnt);
}

Laptop::~Laptop()
{
	delete[] name;
}

void Laptop::Input()
{
	char buf[20];
	cout << "Enter name -> ";
	cin.getline(buf, 20);
	if (name != nullptr)
	{
		delete[] name;
	}
	this->name = new char[strlen(buf) + 1];
	strcpy_s(this->name, strlen(buf) + 1, buf);

	hdd.Input();
	gpu.Input();
	cp.Input();
	ram.Input();

	cout << "Enter price -> ";
	cin >> price;
}

void Laptop::Print()
{
	cout << "-Laptop-\n";
	cout << "Name: " << name << "\n";
	cout << "Price: " << price << "\n";

	hdd.Print(true);
	gpu.Print(true);
	cp.Print(true);
	ram.Print(true);

	if (mss != nullptr)
		for (int i = 0; i < mssCnt; i++)
			mss[i].Print(true);
	if (prnts != nullptr)
		for (int i = 0; i < prntsCnt; i++)
			prnts[i].Print(true);
	if (wcams != nullptr)
		for (int i = 0; i < wcamsCnt; i++)
			wcams[i].Print(true);
}

const char* Laptop::getName()const
{
	return name;
}

Hdd Laptop::getHDD()const
{
	return hdd;
}

GPU Laptop::getGPU()const
{
	return gpu;
}

CP Laptop::getCP()const
{
	return cp;
}

RAM Laptop::getRAM()const
{
	return ram;
}

double Laptop::getPrice()const
{
	return price;
}

Mouse* Laptop::getMouses()const
{
	return mss;
}

WebCamera* Laptop::getWebCameras()const
{
	return wcams;
}

Printer* Laptop::getPrinters()const
{
	return prnts;
}

void Laptop::setName(const char* n)
{
	if (name != nullptr)
		delete[] name;

	int len = strlen(n) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, n);
}

void Laptop::setHDD(Hdd& h)
{
	this->hdd.setName(h.getName());
	this->hdd.setPrice(h.getPrice());
}

void Laptop::setGPU(GPU& g)
{
	this->gpu.setName(g.getName());
	this->gpu.setPrice(g.getPrice());
}

void Laptop::setCP(CP& c)
{
	this->cp.setName(c.getName());
	this->cp.setGhz(c.getGhz());
	this->cp.setPrice(c.getPrice());
}

void Laptop::setRAM(RAM& r)
{	
	this->ram.setName(r.getName());
	this->ram.setPrice(r.getPrice());
}

void Laptop::setPrice(double pr)
{
	price = pr;
}

void Laptop::setMouses(Mouse* m, int mCnt)
{
	this->mssCnt = mCnt;
	this->mss = new Mouse[mssCnt];

	for (int i = 0; i < mssCnt; i++)
	{
		mss[i] = m[i];
	}
}

void Laptop::setWebCameras(WebCamera* wc, int wcCnt)
{
	this->wcamsCnt = wcCnt;
	this->wcams = new WebCamera[wcamsCnt];

	for (int i = 0; i < wcamsCnt; i++)
	{
		wcams[i] = wc[i];
	}
}

void Laptop::setPrinters(Printer* prt, int prtCnt)
{
	this->prntsCnt = prtCnt;
	this->prnts = new Printer[prntsCnt];

	for (int i = 0; i < prntsCnt; i++)
	{
		prnts[i] = prt[i];
	}
}
