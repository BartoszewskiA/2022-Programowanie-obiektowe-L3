#include <iostream>
#include <sstream>

using namespace std;

class punkt
{
protected:
    int x;
    int y;

public:
    punkt() : x(0), y(0) {}
    punkt(int px, int py) : x(px), y(py) {}
    void setX(int x) { this->x = x; }
    void setY(int Y) { this->y = y; }
    int getX() { return x; }
    int getY() { return y; }
    string info()
    {
        stringstream temp;
        temp << "("
             << x
             << ";"
             << y
             << ") ";
        return temp.str();
    }
};

class okrag : public punkt
{
protected:
    int r;

public:
    okrag() : punkt(), r(0) {}
    okrag(int px, int py, int pr) : punkt(px, py), r(pr) {}
    void setR(int r) { this->r = r; }
    int getR() { return r; }
    double getObwod()
    {
        return 2 * 3.14 * r;
    }

    string info()
    {
        stringstream temp;
        temp << punkt::info()
             << " r = "
             << r
             << " Ob = "
             << getObwod();
        return temp.str();
    }
};

class kolo : public okrag
{
public:
    kolo() : okrag() {}
    kolo(int px, int py, int pr) : okrag(px, py, pr) {}
    double getPole()
    {
        return 3.14 * r * r;
    }
    string info()
    {
        stringstream temp;
        temp << okrag::info()
             << " P = "
             << getPole();
        return temp.str();
    }
};

class prostokat: public punkt
{
    
};

kolo o1(3, 4, 5);

int main()
{
    cout << o1.info();
    return 0;
}