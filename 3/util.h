#include <algorithm> 

class stackNode
{
    public:
        stackNode *next;
        int data;
        
        stackNode(int data)
        {
            this->data = data;
        }
        stackNode(char data)
        {
            this->data = data;
        }
};

class Stack
{
    public:
        stackNode *top;
        
        int pop()
        {
            if(this->isEmpty())
            {
                return -1;
            }
            int item = top->data;
            top = top->next;
            return item;
        }
        void push(int item)
        {
            stackNode *t = new stackNode(item);
            t->next = top;
            top = t;
        }
        int peek()
        {
            if(top == nullptr)
            {
                return -1;
            }
            return top->data;
        }
        bool isEmpty()
        {
            return top == nullptr;
        }
};
