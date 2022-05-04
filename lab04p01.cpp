#include <iostream>
#include <ctime>

using namespace std;

class osoba
{
private:
    string imie;
    string nazwisko;
    int rok_urodzenia;

public:
    osoba(string im = "NN", string nazw = "NN", int wiek = 0) : imie(im), nazwisko(nazw)
    {
        for (int i = 0; i < imie.length(); i++)
            imie[i] = toupper(imie[i]);
        for (int i = 0; i < nazwisko.length(); i++)
            nazwisko[i] = toupper(nazwisko[i]);
        time_t czas = time(NULL);
        tm * czasLokalny= localtime(&czas);
        rok_urodzenia = (1900+ czasLokalny->tm_year) - wiek;
    }

    void setImie(string im)
    {
        for (int i = 0; i < im.length(); i++)
            im[i] = toupper(im[i]);
        imie = im;
    }

    void setNazwisko(string nazw)
    {
        for (int i = 0; i < nazw.length(); i++)
            nazw[i] = toupper(nazw[i]);
        nazwisko = nazw;
    }
    // string getImie() {return imie;}
    // string getNazwisko() { return nazwisko; }
    void setWiek(int wiek)
    {
        time_t czas = time(NULL);
        tm *czasLokalny = localtime(&czas);
        rok_urodzenia = (1900 + czasLokalny->tm_year) - wiek;
    }
    int getWiek()
    {
        time_t czas = time(NULL);
        tm *czasLokalny = localtime(&czas);
        return  (1900 + czasLokalny->tm_year) - rok_urodzenia;
    }

    string getNazwisko()
    {
        string s = nazwisko;
        for (int i = 1; i < s.length(); i++)
            s[i] = towlower(s[i]);
        int poz = s.find('-');
        if (poz > 0)
            s[poz + 1] = toupper(s[poz + 1]);
        return s;
    }

    string getImie()
    {
        string s = imie;
        for (int i = 1; i < s.length(); i++)
            s[i] = towlower(s[i]);
        int poz = s.find(' ');
        if (poz > 0)
            s[poz + 1] = toupper(s[poz + 1]);
        return s;
    }
};
int main()
{
    osoba ktos("jan MARIA", "RokitA");
    cout << ktos.getImie() << " " << ktos.getNazwisko();
    return 0;
}