#include "util.h"
#include <cstdlib>
#include <iostream>


using namespace std;


class myQueue
{
    public:
        Stack *one;
        Stack *two;

        
        myQueue()
        {
            one = new Stack();
            two = new Stack();
        }
        
        void push(int data)
        {
            one->push(data);
        }

        int pop()
        {
            while(!one->isEmpty())
            {
                two->push(one->pop());
            }
            
            int ret = two->pop();

            while(!two->isEmpty())
            {
                one->push(two->pop());
            }

            return ret;
        }
};

int main(void)
{
    
    myQueue *q = new myQueue();



    for(int i = 0; i < 5; i++)
    {
        q->push(i);
    }


    for(int i = 0; i < 5; i++)
    {
        cout << q->pop() << endl;
    }

}

