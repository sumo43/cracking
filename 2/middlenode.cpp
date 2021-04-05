#include <iostream>
#include <string>
#include "util.h"

using namespace std;

int main(void)
{

    Node *head = new Node(4);
    for(int i = 0; i < 8; i++)
    {
        head->appendToTail(i);
    }

    int loc;
    cin >> loc;

    Node *node = head;

    for(int i = 0; i < loc; i++)
    {
        node = node->next;
    }
    
    *node = *node->next; 
    head->print();
}
