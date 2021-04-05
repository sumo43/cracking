#include <iostream>
#include <string>
#include "util.h"
#include <algorithm>
#include <stack>

using namespace std;
int main(void)
{
    Node *head = new Node('a');
    for(int i = 0; i < 6; i++)
    {
        char num;
        cin >> num;
        head->appendToTail(num);
    }

    //use a stack to check the order of the letters, potentially ignoring a middle letter
   stack<int> check;

    //check the length of the palindrome
    int len = head->size();
    Node* node = head;
    

    int half = len / 2;

    for(int i = 0; i < half; i++)
    {
        check.push(node->data);
        node = node->next;
    } 

    if(len % 2 != 0)
    {
        node = node->next;
    }

    while(node != nullptr)
    {
        if(node->data != check.top())
        {
            cout << "Not a palindrome" << endl;
            return 1;
        } 
        check.pop();
        node = node->next;

    } 

    cout << "is a palindrome" << endl;
    return 0;

}
