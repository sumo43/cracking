#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Node
{
    public:

    Node *next;
    int data;

    Node()
    {
        next = nullptr;
        data = 0;
    }

    Node(char d)
    {
        data = d;
        next = nullptr;
    }

    Node(int d)
    {
        data = d;
        next = nullptr;
    }

    //only use these with head node

    void appendToTail(int data)
    {
        Node *node = this;

        while(node->next != nullptr)
        {
            node = node->next;
        }
        node->next = new Node(data);
    }
    
    Node *end()
    {
        Node *node = this;
        while(node->next != nullptr)
        {
            node = node->next;
        }
        return node;
    }
    void print()
    {
        Node *node = this;

        while(node != nullptr)
        {
            cout << node->data << endl;
            node = node->next;
        }
    }
    void printChar()
    {
        Node *node = this;
        while(node != nullptr)
        {
            cout << char(node->data) << endl;
            node = node->next;
        } 
    } 
    int size()
    {
        Node *node = this;
        int i = 0;

        while(node != nullptr)
        {
            node = node->next;
            i++;
        }

        return i;

    }

};
