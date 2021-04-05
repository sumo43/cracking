#include <iostream>
#include <string>
#include "util.h"
#include <vector>

using namespace std;

int main(void)
{

    Node *head = new Node(2);
    for(int i = 0; i < 5; i++)
    {
        head->appendToTail(i);
    }
    int bufferSize = 0;

    Node *node = head;
    while(node->next != nullptr)
    {
        bufferSize++;
        node = node->next;
    }

    vector<int> buffer;

    node = head->next;   
    Node *node2 = head; 

    buffer.push_back(node2->data);

    while(node2->next != nullptr)
    {
        for(int b : buffer)
        {
            if(node->data == b)
            {
                if(node->next == nullptr)
                {
                    node2->next = nullptr;  
                }
                else
                {
                    *node2->next = *node->next;
                }
            }
        }

        if(node2->next != nullptr)
        {
            buffer.push_back(node->data);
            node = node->next;
            node2 = node2->next;
        } 

    }

    cout << "No dupes" << endl;


    while(head != nullptr)
    {
        cout << head->data << endl;
        head = head->next;
    }

    return 0;



}
