#include "WebCamera.h"
#include <iostream>
using namespace std;

WebCamera::WebCamera(bool hm)
{
    hasMicro = hm;
}

WebCamera::WebCamera(bool hm, double pr)
    : WebCamera(hm)
{
    price = pr;
}

WebCamera::WebCamera()
{
    name = nullptr;
    videoQuality = nullptr;
    hasMicro = false;
    color = nullptr;
    price = 0;
}

WebCamera::WebCamera(const char* n, const char* vq, bool hm, const char* col, double pr)
    : WebCamera(hm, pr)
{
    int len = strlen(n) + 1;
    name = new char[len];
    strcpy_s(name, len, n);

    len = strlen(vq) + 1;
    videoQuality = new char[len];
    strcpy_s(videoQuality, len, vq);

    len = strlen(col) + 1;
    color = new char[len];
    strcpy_s(color, len, col);
}

WebCamera::WebCamera(const WebCamera& wc) 
    : WebCamera(wc.hasMicro, wc.price)
{
    if (name != nullptr)
        delete[] name;
    if (videoQuality != nullptr)
        delete[] videoQuality;
    if (color != nullptr)
        delete[] color;

    int len = strlen(wc.name) + 1;
    name = new char[len];
    strcpy_s(name, len, wc.name);

    len = strlen(wc.videoQuality) + 1;
    videoQuality = new char[len];
    strcpy_s(videoQuality, len, wc.videoQuality);

    len = strlen(wc.color) + 1;
    color = new char[len];
    strcpy_s(color, len, wc.color);
}

WebCamera::~WebCamera()
{
    delete[] name;
    delete[] videoQuality;
    delete[] color;
}

void WebCamera::Input()
{
    char buf[100];

    cout << "Enter name -> ";
    cin.getline(buf, 100);
    setName(buf);

    cout << "Enter video quality -> ";
    cin.getline(buf, 100);
    setVideoQuality(buf);

    cout << "Has microphone -> ";
    cin >> boolalpha >> hasMicro;
    cin.ignore();

    cout << "Enter color -> ";
    cin.getline(buf, 100);
    setColor(buf);

    cout << "Enter price -> ";
    cin >> price;
    cin.ignore();
}

void WebCamera::Print(bool inner = false)
{
    if (!inner)
    {
        cout << "-Web Camera-\n";
        cout << "Name: " << name << "\n";
        cout << "Video quality: " << videoQuality << "\n";
        cout << boolalpha << "Has microphone: " << hasMicro << "\n";
        cout << "Color: " << color << "\n";
        cout << "Price: " << price << "\n";
    }
    else
    {
        cout << "  " << "-Web Camera-\n";
        cout << "    " << "Name: " << name << "\n";
        cout << "    " << "Video quality: " << videoQuality << "\n";
        cout << "    " << boolalpha << "Has microphone: " << hasMicro << "\n";
        cout << "    " << "Color: " << color << "\n";
        cout << "    " << "Price: " << price << "\n";
    }
}

const char* WebCamera::getName() const
{
    return name;
}

const char* WebCamera::getVideoQuality() const
{
    return videoQuality;
}

bool WebCamera::getHasMicrophone() const
{
    return hasMicro;
}

const char* WebCamera::getColor() const
{
    return color;
}

double WebCamera::getPrice() const
{
    return price;
}

void WebCamera::setName(const char* n)
{
    if (name != nullptr)
        delete[] name;

    int len = strlen(n) + 1;
    name = new char[len];
    strcpy_s(name, len, n);
}

void WebCamera::setVideoQuality(const char* vq)
{
    if (videoQuality != nullptr)
        delete[] videoQuality;

    int len = strlen(vq) + 1;
    videoQuality = new char[len];
    strcpy_s(videoQuality, len, vq);
}

void WebCamera::setHasMicrophone(bool hm)
{
    hasMicro = hm;
}

void WebCamera::setColor(const char* col)
{
    if (color != nullptr)
        delete[] color;

    int len = strlen(col) + 1;
    color = new char[len];
    strcpy_s(color, len, col);
}

void WebCamera::setPrice(double pr)
{
    price = pr;
}

WebCamera& WebCamera::operator = (const WebCamera& wc)
{
    if (&wc != this)
    {
        if (name != nullptr)
            delete[] name;
        if (videoQuality != nullptr)
            delete[] videoQuality;
        if (color != nullptr)
            delete[] color;

        int len = strlen(wc.name) + 1;
        name = new char[len];
        strcpy_s(name, len, wc.name);

        len = strlen(wc.videoQuality) + 1;
        videoQuality = new char[len];
        strcpy_s(videoQuality, len, wc.videoQuality);

        len = strlen(wc.color) + 1;
        color = new char[len];
        strcpy_s(color, len, wc.color);

        hasMicro = wc.hasMicro;
        price = wc.price;
    }
    return *this;
}
