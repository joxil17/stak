#pragma once
#include<iostream>
using namespace std;

class Stacks
{
   int maxsize = 10;
   char* sumbol;                  
    int top; 
public:
    Stacks() : sumbol{ 0 }, top{ -1 }
    { }
   
    Stacks(int _size) {
        maxsize = _size;
        sumbol = new char[_size];
        top = -1;

    }
    void Push(char obj)
    {
        if (!IsFull())
            sumbol[++top] = obj;
        else
        {
            maxsize *= 2;
            char* tmp = new char[maxsize];
            for (int i = 0; i <= top; ++i)
                tmp[i] = sumbol[i];
            delete[] sumbol;
            sumbol = tmp;
            tmp = nullptr;

            sumbol[++top] = obj;
        }

    }
   char Pop()
    {
        if (!IsEmpty())
            return sumbol[top--];
        else
            return 0;
    }
    void Clear()
    {
        top = -1;
    }
    bool IsEmpty()
    {
        return top == -1;
    }
    bool IsFull()
    {
        return top == maxsize - 1;
    }
    int GetCount()
    {
        return top + 1;
    }
    char GetElement()
    {
        if (!IsEmpty())
            return sumbol[top];
        else
            return 0;
    }
};
