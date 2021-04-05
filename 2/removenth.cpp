#include <iostream>
#include <string>
#include "util.h"

using namespace std;

int main(void)
{

    int val;
    cin >> val;

    Node *head = new Node(4);
    Node *head2 = head;

    for(int i = 0; i < 8; i++)
    {
        head->appendToTail(i);
    }

    for(int i = 0; i < val - 2; i++)
    {
        head = head->next;
    }

    *head->next = *head->next->next;


    while(head2 != nullptr)
    {
        cout << head2->data << endl;

        head2 = head2->next;
    }

}