#include "stack.h"
using namespace std;

Stack stackA = Stack();
Stack stackB = Stack();

void enque(int data)
{
    int temp = stackB.pop();
    while(temp != -1)
    {
        stackA.push(temp);
        temp = stackB.pop();
    }
    stackB.push(data);
    temp = stackA.pop();
    while(temp != -1)
    {
        stackB.push(temp);
        temp = stackA.pop();
    }

}
int deque()
{
    return stackB.pop();
}
int peek()
{
    return stackB.peek();
}
void display()
{
    while(!stackB.isEmpty())
        cout << stackB.pop() << " - ";
}


int main()
{
    int choice,temp,flag = 1;

    while(flag)
    {
        cout << "Queue" << endl;
        cout << "1. Enque" << endl;
        cout << "2. Deque" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Quit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Value : ";
            cin >> temp;
            enque(temp);
            break;
        case 2:
            temp = deque();
            if (temp != -1)
                cout << temp << endl;
            else
                cout << "Underflow" << endl;
            break;
        case 3:
            cout << peek() << endl;
            break;
        case 4:
            display();
            flag = 0;
            break;
        default:
            cout << "Invalid" << endl;

        }
    }

}
