#include <iostream>
#include <string>
#include "util.h"

using namespace std;
int main(void)
{
    Node *one = new Node(4);
    one->appendToTail(3);
    one->appendToTail(2);
    
    Node *two = new Node(5);

    if(one == two)
    {
        cout << "nodes intersect" << endl;
        return 0;
    }


    two->appendToTail(6);
    two->appendToTail(7);

    Node *end = one->end();    
    Node *end_two = two->end();
    
    end_two->next = end;

    one->appendToTail(3);
    one->appendToTail(3);
    one->appendToTail(3);

    if(one->end() == two->end())
    {
        cout << "Nodes intersect" << endl;
        return 0;
    }
    cout << "Nodes do not intersect" << endl;
    return 1;
}

