#include <iostream>
#include <sstream>

using namespace std;

class RGB;
class ARGB;

class RGB
{
protected:
    int R;
    int G;
    int B;

public:
    RGB(int r = 0, int g = 0, int b = 0) : R(r), G(g), B(b) {}
    string toString()
    {
        stringstream temp;
        temp << "R="
             << R
             << " G="
             << G
             << " B="
             << B;
        return temp.str();
    }
    friend RGB *dodaj(RGB &k1, RGB &k2);
    friend ARGB *dodaj(RGB &k1, ARGB &k2);
    friend ARGB *dodaj(ARGB &k1, RGB &k2);
    friend ARGB *dodaj(ARGB &k1, ARGB &k2);
};

class ARGB : public RGB
{
protected:
    int A;

public:
    ARGB(int a = 255, int r = 0, int g = 0, int b = 0) : RGB(r, g, b), A(a) {}
    string toString()
    {
        stringstream temp;
        temp << "A="
             << A
             << " ";
        temp << RGB::toString();
        return temp.str();
    }
    friend ARGB *dodaj(RGB &k1, ARGB &k2);
    friend ARGB *dodaj(ARGB &k1, RGB &k2);
    friend ARGB *dodaj(ARGB &k1, ARGB &k2);
};

RGB *dodaj(RGB &k1, RGB &k2)
{
    int r = (k1.R + k2.R) / 2;
    int g = (k1.G + k2.G) / 2;
    int b = (k1.B + k2.B) / 2;
    RGB *wynik = new RGB(r, g, b);
    return wynik;
}

ARGB *dodaj(RGB &k1, ARGB &k2)
{
    int a = (255 + k2.A) / 2;
    int r = (k1.R + k2.R) / 2;
    int g = (k1.G + k2.G) / 2;
    int b = (k1.B + k2.B) / 2;
    ARGB *wynik = new ARGB(r, g, b);
    return wynik;
}

ARGB *dodaj(ARGB &k1, RGB &k2)
{
    int a = (k1.A + 255) / 2;
    int r = (k1.R + k2.R) / 2;
    int g = (k1.G + k2.G) / 2;
    int b = (k1.B + k2.B) / 2;
    ARGB *wynik = new ARGB(r, g, b);
    return wynik;
}

ARGB *dodaj(ARGB &k1, ARGB &k2)
{
    int a = (k1.A + k2.A) / 2;
    int r = (k1.R + k2.R) / 2;
    int g = (k1.G + k2.G) / 2;
    int b = (k1.B + k2.B) / 2;
    ARGB *wynik = new ARGB(r, g, b);
    return wynik;
}

int main()
{

    return 0;
}