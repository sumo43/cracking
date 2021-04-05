#include <iostream>
#include <string>
#include "util.h"

using namespace std;
int num(Node *node)
{
    int val = 0;
    while(node != nullptr)
    {
        val *= 10;
        val += node->data;
        node = node->next;
    }

    return val;
}

int numReverse(Node *node)
{
    int val = 0;
    int place = 1;
    while(node != nullptr)
    {
        val += node->data * place;
        place *= 10;
        node = node->next;
    }

    return val;
} 
        

int main(void)
{
    Node *one = new Node(7);
    one->appendToTail(1);
    one->appendToTail(6);

    Node *two = new Node(5);
    two->appendToTail(9);
    two->appendToTail(2);

    cout << num(one) << endl;
    cout << num(two) << endl;
    cout << numReverse(one) << endl;
    cout << numReverse(two) << endl;

}
 
