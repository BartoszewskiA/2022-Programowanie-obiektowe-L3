#include <iostream>
#include <ctime>

using namespace std;
class pudelko
{
private:
    int kot; //-1 Martwy, 0 - nieustalony, 1 - zywy
public:
    pudelko() { kot = 0; }
    string otworz()
    {
        if (kot == 0)
        {
            int los = rand() % 2;
            if (los == 0)
                kot = -1;
            else
                kot = 1;
        }
        if (kot == -1)
            return "martwy";
        else
            return "zywy";
    }
};

int main()
{
    srand(time(NULL));
    pudelko p;
    cout <<p.otworz()<<" ";
    cout << p.otworz() << " ";
    cout << p.otworz() << " ";
    cout << p.otworz() << " ";
    return 0;
}