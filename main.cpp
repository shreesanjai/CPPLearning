#include <iostream>
#include "addition.h"
using namespace std;

class Calculator
{
private:
    int a, b;

public:
    void setA(int temp)
    {
        a = temp;
    }
    void setB(int temp)
    {
        b = temp;
    }
    int add()
    {
        return a + b;
    }
};

int add(int a,int b);

int main()
{
    int choice;
    Calculator c = Calculator();
    int temp;
    cin >> temp;
    c.setA(temp);
    cin >> temp;
    c.setB(temp);
    cout << c.add() << endl;

    cout<< add(9,7);
    return 0;
}