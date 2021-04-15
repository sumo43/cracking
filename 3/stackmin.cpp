#include <cstdio>
#include <iostream>
#include "util.h"

using namespace std;

class minStack
{
    public:
        int min;
        stackNode *top;
        minStack()
        {
        }

        void push(int data)
        {
            if(top == nullptr)
            {
                top = new stackNode(data);
                min = data;
            }
            else
            {
                top->next = new stackNode(data);
                top = top->next;
                if(data < min)
                {
                    min = data;
                }

            }
        }

        int pop()
        {
            if(top == nullptr)
            {
                return -1;
            }
            else
            {
                return top->data;
            }
        }

        int getMin()
        {
            return min;
        }

        bool isEmpty()
        {
            return top == nullptr;
        }

};

        
int main(void)
{
    minStack *min = new minStack();
    for(int i = 3; i < 5; i++)
    {
        min->push(i);
    }
    cout << min->getMin() << endl;
}
