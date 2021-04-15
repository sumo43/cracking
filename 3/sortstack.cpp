#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include "util.h"

using namespace std;

class sortedStack
{
    Stack *one;
    Stack *two;
    public:
        sortedStack(int data)
        {
            one = new Stack();
            two = new Stack();
            one->push(data);
        }

        void push(int data)
        {
            while(!one->isEmpty() && one->peek() < data)
            {
                two->push(one->pop());
            }
            one->push(data);
            if(!two->isEmpty())
            {
                while(!two->isEmpty())
                {
                    one->push(two->pop());
                }
            }
        }

        int pop()
        {
            return one->isEmpty() ? -1 : one->pop();
        }

        int peek()
        {
            return one->isEmpty() ? -1 : one->peek();
        }

        int isEmpty()
        {
            return one->isEmpty();
        }
};

int main(void)
{
    sortedStack *s = new sortedStack(4);
    s->push(8);
    s->push(2);

    cout << s->pop() << endl;

    s->push(6);
    s->push(3);


    for(int i = 0; i < 4; i++)
    {
        cout << s->pop() << endl;
    }
}


