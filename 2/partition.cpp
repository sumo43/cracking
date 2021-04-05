#include <iostream>
#include <string>
#include "util.h"

using namespace std;

int main(void)
{
    Node *head = new Node(3);
    head->appendToTail(5);
    head->appendToTail(8);
    head->appendToTail(5);
    head->appendToTail(10);
    head->appendToTail(2);
    head->appendToTail(1);
    
    int part;
    cin >> part;

    Node *node = head;
    while(node->data != part)
    {
        node = node->next;
    }

    while(node->next != nullptr)
    {
        if(node->next->data < part)
        {
            Node *temp = new Node(node->next->data);
            temp->next = head->next;
            head->next = temp;
            if(node->next->next == nullptr)
            {
                node->next = nullptr;
            }
            else
            {
                *node->next = *node->next->next;
            }

        }
        else
        {
            node = node->next;
        }

    }

    head->print();
}

