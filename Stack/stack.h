#include <iostream>
#include <stdlib.h>
#define null nullptr

struct Node
{
    int data;
    struct Node *next = null;
};

class Stack
{

private:
    struct Node *top;

public:
    Stack()
    {
        top = null;
    }
    void push(int data)
    {
        struct Node *temp = (Node *)malloc(sizeof(Node));
        temp->data = data;

        if (top == null)
        {
            top = temp;
            top->next = null;
        }
        else
        {
            temp->next = top;
            top = temp;
        }
    }

    int pop()
    {
        int temp = -1;
        if (top != null)
        {
            temp = top->data;
            top = top->next;
        }

        return temp;
    }

    int peek()
    {
        if (top != null)
            return top->data;
        return -1;
    }

    void display()
    {
        struct Node *tempPointer = top;
        while (tempPointer != null)
        {
            std::cout << tempPointer->data << " - ";
            tempPointer = tempPointer->next;
        }
        // cout << "null"; // Optional: Indicate the end of the stack
    }
    bool isEmpty()
    {
        if(top == null)
            return true;
        return false;
    }
};