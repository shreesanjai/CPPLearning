#include <iostream>
using namespace std;
int main()
{

    int n = 5;

    int *ptr = new int;

    for (int i = 0; i < n; i++)
        cin >> *(ptr + i);

    for (int i = 0; i < n; i++)
        cout << *(ptr + i) << "-";
    cout << endl;

    for (int i = 0; i < n/2; i++)
    {
        int temp = *(ptr+i);
        *(ptr+i) = *(ptr+n-1-i);
        *(ptr+n-1-i) = temp;
    }
        
    for (int i = 0; i < n; i++)
        cout << *(ptr + i) << "-";
    
    delete[] ptr;
}