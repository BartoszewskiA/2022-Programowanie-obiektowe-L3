#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

const int DL = 10;

class wektor
{
private:
    int x;
    int y;

public:
    void setX(int px) { x = px; }
    void setY(int py) { y = py; }
    int getX() { return x; }
    int getY() { return y; }
    double getDlugosc();
    void wylosujXY(int a, int b);
};

double wektor::getDlugosc()
{
    return sqrt(x * x + y * y);
}
void wektor::wylosujXY(int a, int b)
{

    x = rand() % (b - a + 1) + a;
    y = rand() % (b - a + 1) + a;
}

wektor* tab[DL];

void wypisz();
void losuj(int a, int b);
double szukaj_max();
void posprzataj();

int main()
{
    losuj(-20, 100);
    wypisz();
    cout << endl
         << "max=" << szukaj_max();
    posprzataj();
    return 0;
}

void losuj(int a, int b)
{
    srand(time(NULL));
    for (int i = 0; i < DL; i++)
    {
        tab[i] = new wektor;
        tab[i]->wylosujXY(-20, 100);
    }
}

double szukaj_max()
{
    double max = 0;
    for (int i = 0; i < DL; i++)
        if (tab[i]->getDlugosc() > max)
            max = tab[i]->getDlugosc();
    return max;
}

void wypisz()
{
    for (int i = 0; i < DL; i++)
    {
        cout << "[" << tab[i]->getX() << ";" << tab[i]->getY() << "] ";
    }
}

void posprzataj()
{
    for (int i = 0; i < DL; i++)
        delete tab[i];
}