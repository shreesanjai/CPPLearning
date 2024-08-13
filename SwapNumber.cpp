#include<iostream>
using namespace std;

int main()
{
    int a = 7;
    int b = 10;

    printf("%d %d\n",a,b);

    //code
    a ^= b;

    b ^= a;

    a ^= b;

    printf("After Swap \n");
    printf("%d %d\n",a,b);
}