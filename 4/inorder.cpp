#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;

template<class T>
class Solution {

   struct Node {

       T data;
       Node *left, right;
       Node() : left(nullptr), right(nullptr) {}; 
       Node(const T value) : data(value), left(nullptr), right(nullptr) {};

};

class Node
{
    public:
        int data;
        Node *right;
        Node *left;
        Node(int data)
        {
            this->data = data;
        }
        Node()
        {
        }
};   

Node *next(Node *head)
{
    if(head->left == nullptr)
    {
        if(head->right == nullptr)
        {
            return nullptr;
        }
        return head->right;
    }
    return head->left;
}


int main(void)
{
}


