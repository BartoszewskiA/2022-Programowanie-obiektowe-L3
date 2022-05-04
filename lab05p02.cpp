#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

class test
{
private:
    string Id;

public:
    test(string s) : Id(s)
    {
        time_t czas = time(NULL);
        tm *czas_l = localtime(&czas);
        fstream plik;
        plik.open("log.txt", ios::app);
        plik << Id << " "
             << "utworzony: "
             << czas_l->tm_hour << ":"
             << czas_l->tm_min << ":"
             << czas_l->tm_sec << endl;
        plik.close();
    }

    ~test()
    {
        time_t czas = time(NULL);
        tm *czas_l = localtime(&czas);
        fstream plik;
        plik.open("log.txt", ios::app);
        plik << Id << " "
             << "usuniety: "
             << czas_l->tm_hour << ":"
             << czas_l->tm_min << ":"
             << czas_l->tm_sec << endl;
        plik.close();
    }
};

int main()
{
    //test p01("Obiekt 1"), p02("Obiekt 2");
    test *po1 = new test("ob. 3");

    cout<<"press any key";
    getchar();
    delete po1;
    return 0;
}