#pragma once
class WebCamera
{
	char* name;
	char* videoQuality;
	bool hasMicro;
	char* color;
	double price;

    WebCamera(bool hm);
    WebCamera(bool hm, double pr);

public:
    WebCamera();
    WebCamera(const char* n, const char* vq, bool hm, const char* col, double pr);
    WebCamera(const WebCamera& wc);
    ~WebCamera();

    void Input();
    void Print(bool inner);

    const char* getName() const;
    const char* getVideoQuality() const;
    bool getHasMicrophone() const;
    const char* getColor() const;
    double getPrice() const;

    void setName(const char* n);
    void setVideoQuality(const char* vq);
    void setHasMicrophone(bool hm);
    void setColor(const char* col);
    void setPrice(double pr);

    WebCamera& operator=(const WebCamera& wc);
};

