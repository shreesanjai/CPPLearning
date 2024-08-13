#include <iostream>
using namespace std;

class NormalCheck
{
private:
    int a, b, c;

public:
    NormalCheck() : a{}, b{}, c{}
    {
        cout << "\nEmpty Object Constructed";
    }

    NormalCheck(int a1, int b1, int c1) : a{a1}, b{b1}, c{c1}
    {
        cout << "\nConstructed";
    }

    // NormalCheck(const NormalCheck &copy) : a{copy.a}, b{copy.b}, c{copy.c}
    // {
    //     cout << "\nCopy created";

    // }
    NormalCheck(const NormalCheck &copy) = default;

    void display()
    {

        cout << "\nValue of a : " << a << endl;
        cout << "Value of b : " << b << endl;
        cout << "Value of c : " << c << endl;
    }
    void setB(int val)
    {
        b = val;
    }
};

int main()
{
    NormalCheck dummy{};
    dummy.display();

    NormalCheck a{1, 3, 3};
    a.display();

    NormalCheck vpy{a};
    vpy.display();

    a.setB(8);
    a.display();

    vpy.setB(100);
    vpy.display();
}