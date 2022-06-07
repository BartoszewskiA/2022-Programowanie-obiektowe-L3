#include <iostream>

using namespace std;

class zesp
{
protected:
    double a;
    double b;

public:
    zesp(double A = 0, double B = 0) : a(A), b(B) {}
    // zesp operator+(zesp z2)
    // {
    //     double a = this->a + z2.a;
    //     double b = this->b + z2.b;
    //     return zesp(a,b);
    // }
    // zesp operator-(zesp z2)
    // {
    //     double a = this->a - z2.a;
    //     double b = this->b - z2.b;
    //     return zesp(a,b);
    // }
    // zesp operator-()
    // {
    //     double a = this->a;
    //     double b = this->b;
    //     return zesp(a, b);
    // }
    friend ostream &operator<<(ostream &s, zesp z);
    friend zesp operator+(zesp z1, zesp z2);
    friend zesp operator-(zesp z1, zesp z2);
    friend zesp operator-(zesp z);
};

zesp operator+(zesp z1, zesp z2)
{
    double a = z1.a + z2.a;
    double b = z2.b + z2.b;
    return zesp(a, b);
}

zesp operator-(zesp z1, zesp z2)
{
    double a = z1.a - z2.a;
    double b = z2.b - z2.b;
    return zesp(a, b);
}

zesp operator-(zesp z)
{
    double a = -z.a;
    double b = -z.b;
    return zesp(a, b);
}

ostream &operator<<(ostream &s, zesp z)
{
    if (z.a != 0)
        s << z.a;
    if (z.b > 0)
        s << "+";
    if (z.b != 0)
        s << z.b << "i";
    return s;
}
int main()
{
    zesp liczba01(4, 5);
    cout << liczba01;
    return 0;
}