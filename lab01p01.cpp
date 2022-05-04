#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int DL = 256;
struct wpis
{
    char znak;
    int ile;
};

wpis *tab[DL];

void zeruj_tablice();
void dodaj(char x);
void wypisz();
void usun_wpisy();
void czytaj_plik();

    int main()
{
    zeruj_tablice();
    // dodaj('z');
    // dodaj('a');
    // dodaj('a');
    // dodaj('n');
    // dodaj('a');
    czytaj_plik();
    wypisz();
    usun_wpisy();
    return 0;
}

void zeruj_tablice()
{
    for (int i = 0; i < DL; i++)
        tab[i] = NULL;
}
void dodaj(char x)
{
    int poz = 0;
    while (tab[poz] != NULL && tab[poz]->znak != x)
    {
        poz++;
    }

    if (tab[poz] == NULL)
    {
        tab[poz] = new wpis;
        tab[poz]->znak = x;
        tab[poz]->ile = 1;
    }
    else
    {
        tab[poz]->ile = tab[poz]->ile + 1;
    }
}

void wypisz()
{
    int poz = 0;
    while (tab[poz] != NULL)
    {
        cout << tab[poz]->znak << "-" << tab[poz]->ile << "\t";
        poz++;
    }
}

void usun_wpisy()
{
    int poz = 0;
    while (tab[poz] != NULL)
    {
        delete tab[poz];
        poz++;
    }
}
void czytaj_plik()
{
    fstream plik;
    string s;
    plik.open("dane.txt", ios::in);
    while(!plik.eof())
    {
        getline(plik,s);
        for (int i=0; i<s.length(); i++)
            dodaj(s[i]);
    }
    plik.close();
}
