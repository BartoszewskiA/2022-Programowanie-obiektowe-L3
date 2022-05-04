#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;
class r_kwadrat
{
private:
    int a;
    int b;
    int c;
    int delta;
    double x1;
    double x2;

public:
    r_kwadrat(int a, int b, int c);
    int getA() { return a; }
    int getB() { return b; }
    int getC() { return c; }
    int getDelta() { return delta; }
    // double getX1() { return x1; }
    // double getX2() { return x2; }
    string getX1();
    string getX2();
    string toString();
};

r_kwadrat::r_kwadrat(int a, int b, int c)
{
    this->a = a;
    this->b = b;
    this->c = c;
    delta = (b * b) - (4 * a * c);
    if (delta > 0)
    {
        x1 = (-b - sqrt(delta)) / (2 * a);
        x2 = (-b + sqrt(delta)) / (2 * a);
    }
    else if (delta == 0)
        x1 = x2 = (-b) / (2 * a);
}

string r_kwadrat::getX1()
{
    stringstream wynik;
    if (delta >= 0)
        wynik << x1;
    else
        wynik << "";
    return wynik.str();
}

string r_kwadrat::getX2()
{
    stringstream wynik;

    if (delta >= 0)
        wynik << x1;
    else
        wynik << "";
    return wynik.str();
}

string r_kwadrat::toString()
{
    stringstream wynik;
    wynik << "a=" << a << " b=" << b << " c=" << c << " delta=" << delta << endl;
    if (delta > 0)
        wynik << "x1=" << x1 << " x2=" << x2;
    else if (delta == 0)
        wynik << "x0=" << x1;
    else
        wynik << "brak rozwiazan";
    return wynik.str();
}

int main()
{
    r_kwadrat r1(1, 1, 1);
    cout << r1.toString();
    // cout << r1.getA() << " " << r1.getB() << " " << r1.getC() << " delta=" << r1.getDelta() << endl;
    // cout << "x1=" << r1.getX1() << " x2=" << r1.getX2();
    return 0;
}