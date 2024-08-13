#include <iostream>
using namespace std;

int main() 
{
    int a = 8;
    int b = 10;
    int* c;
    c = &b;
    cout << *c << endl;
    b = 11;
    cout << *c << endl;
    
    float x {1.50001};
    
    cout << x ;
    
    return 0;
}