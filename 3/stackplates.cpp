#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include "util.h"

using namespace std;

class sPlates
{
    //create a new stack when the old one reaches threshold of 5
    vector<Stack *> plates;
    int threshold = 5;
    int currentStack = 0;


    public:
        
        sPlates()
        {
        }
        
        void push(int data)
        {
            if(plates.empty())
            {
                Stack *s = new Stack();
                s->push(data);
                plates.push_back(s);
                ++currentStack;
            }
            else if(threshold == currentStack)
            {
                Stack *n = new Stack();
                n->push(data);
                plates.push_back(n);
                currentStack = 1;
            }
            else
            {
                Stack *c = plates.back();
                c->push(data);
                ++currentStack;
            }
        }

        int pop()
        {

            if(plates.size() == 1 && plates.back()->isEmpty())
            {
                return -2;
            }

            else if(currentStack == 0)
            {
                plates.pop_back();
                Stack *c = plates.back();
                currentStack = 5;
                return c->pop();
            }
            else
            {
                
                Stack *c = plates.back();
                currentStack--;
                return c->pop();
            }
        }

        int popAt(int index)
        {
            Stack *c = plates.at(index);
            return c->pop();
        }

};

int main(void)
{

    sPlates *plates = new sPlates();

    for(int i = 0; i < 10; i++)
    {
        plates->push(i);
    }


    cout << plates->popAt(0) << endl;


}

