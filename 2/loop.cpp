#include <iostream>
#include <string>
#include "util.h"
#include <algorithm>
#include <stack>

using namespace std;
int main(void)
{
    Node *head = new Node(1);
    Node *loopstart;
    for(int i = 2; i < 7; i++)
    {
        head->appendToTail(i);
        if(i == 3)
        {
            loopstart = head->end();
        }
    }

    Node *end = head->end();


    Node *runner1 = head;
    Node *runner2 = head;
    

    int i = 0;
    int loopSize = 1;

    while(true)
    {
        runner2 = runner1;
        for(int i = 0; i < loopSize; i++)
        {
            runner2 = runner2->next;
            if(runner2->next == nullptr)
            {
                cout << "Not a loop" << endl;
                return 1;
            }
            if(runner2->data == runner1->data)
            {
                cout << "loop" << endl;
                return 0;
            }
        }
        runner1 = runner1->next;
        loopSize++;
        cout << runner1->data << endl;

            
    }


}
