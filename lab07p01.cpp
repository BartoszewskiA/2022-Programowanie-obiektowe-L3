#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

class wektor
{
private:
    int x;
    int y;

public:
    wektor(int px = 0, int py = 0) : x(px), y(py) {}
    double getDlugosc()
    {
        return sqrt(x * x + y * y);
    }
    string toString()
    {
        stringstream temp;
        temp << "[" << x << ";" << y << "]";
        return temp.str();
    }
    friend wektor dodaj(wektor &w1, wektor &w2);
    friend wektor *dodaj_v2(wektor &w1, wektor &w2);
};

wektor dodaj(wektor &w1, wektor &w2)
{
    int x = w1.x + w2.x;
    int y = w1.y + w2.y;
    wektor temp(x, y);
    return temp;
}

wektor* dodaj_v2(wektor &w1, wektor &w2)
{
    int x = w1.x + w2.x;
    int y = w1.y + w2.y;
    wektor* temp = new wektor(x,y);
    return temp;
}

int main()
{
    wektor wektor1(10, 5), wektor2(-4, 3);
    // wektor wynik = dodaj(wektor1,wektor2);
    // cout<< wynik.toString();
    wektor* wynik = dodaj_v2(wektor1,wektor2);
    cout << wynik->toString();
    delete wynik;
    return 0;
}