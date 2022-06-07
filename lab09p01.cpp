#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;
const double PI = 3.14;

class kolo
{
protected:
    double r;

public:
    kolo(double R = 0) : r(R) {}
    void setR(double r) { this->r = r; }
    double getR() { return r; }
    double getObwod() { return 2 * PI * r; }
    double getPole() { return PI * r * r; }
    friend bool porownaj(kolo k1, kolo k2);
    friend bool operator>(kolo k1, kolo k2);
     bool operator>(kolo k2)
    {
        if (this->r > k2.r)
            return true;
        else
            return false;
    }

}; // koniec klasy "kolo"

class stozek : public kolo
{
protected:
    double h; // this->h

public:
    stozek(double R = 0, double H = 0) : kolo(r), h(H) {}
    void setH(double h) { this->h = h; }
    double getH() { return h; }
    double getPole()
    {
        // double l = sqrt(r * r + h * h);
        // double pole = PI * r * l + kolo::getPole();
        // return pole;
        return PI * r * sqrt(r * r + h * h) + kolo::getPole();
    }
    double getObjetosc()
    {
        return (1.0 / 3) * kolo::getPole() * h;
    }
}; // koniec klasy "stozek"


bool operator>(kolo k1, kolo k2)
{
    if (k1.r > k2.r)
        return true;
    else
        return false;
}

kolo operator+(kolo k1, kolo k2)
{
    double pole = k1.getPole() + k2.getObwod();
    double r = sqrt(pole / PI);
    return kolo(r);
}

bool porownaj(kolo k1, kolo k2) // funkcja zaprzyjazniona
{
    if (k1.r == k2.r)
        return true;
    else
        return false;
}

kolo tab_3[] = {
    kolo(10),
    kolo(20),
    kolo(30),
    kolo(40)};

kolo *tab_4[] = {
    new kolo(10),
    new kolo(20),
    new kolo(30),
    new kolo(40)};

int main()
{
    srand(time(NULL));
    kolo tab_1[4];
    for (int i = 0; i < 4; i++)
        tab_1[i].setR(rand() % 101);
    //====================
    kolo *tab_2[4];
    for (int i = 0; i < 4; i++)
        tab_2[i] = new kolo(rand() % 101);
    for (int i = 0; i < 4; i++)
        delete tab_2[i];
    //===================
    for (int i = 0; i < 4; i++)
        delete tab_4[i];
    return 0;
}
