#include <iostream>
using namespace std;

int main()
{

    int n = 5;

    int *ptr = new int;

    int *max = ptr;

    for (int i = 0; i < n; i++)
    {
        cin >> *(ptr + i);
        if (*(ptr + i) > *max)
            max = ptr + i;
    }

    for (int i = 0; i < n; i++)
    {
        cout << *(ptr + i) << " - ";
    }
    cout << "\nMax : " << *max;

    delete ptr;
    delete max;
}