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

    head->print();

    int k;
    cin >> k;

    Node *p1 = head;
    Node *p2 = head;

    for(int i = 0; i < head->size(); i++)
    {
        p1 = p1->next;
        if(i > k)
        {
            p2 = p2->next;
        }
    }    

    cout << p2->data << endl;
}