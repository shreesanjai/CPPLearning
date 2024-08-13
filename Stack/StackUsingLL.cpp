#include "stack.h"
using namespace std;

int main()
{
    Stack stk = Stack();
    int choice, temp, flag = 1;

    while (flag)
    {
        cout << "Stack" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Quit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Value : ";
            cin >> temp;
            stk.push(temp);
            break;
        case 2:
            temp = stk.pop();
            if (temp != -1)
                cout << temp << endl;
            else
                cout << "Underflow" << endl;
            break;
        case 3:
            cout << stk.peek() << endl;
            break;
        case 4:
            stk.display();
            flag = 0;
            break;
        default:
            cout << "Invalid" << endl;
        }
    }
}