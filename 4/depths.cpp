#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;

class Node
{
    public:
        Node *left;
        Node *right;
        int data;
        Node(){}
        Node(int data)
        {
            this->data = data;
        }
};

void searchTree(int level, Node *root, vector<vector<Node *>> lists)
{
    if(level == lists.size())
    {
        vector<Node *>add;
        lists.push_back(add);
    }
    
    vector<Node *> list = lists[level];
    list.push_back(root);

    if(root->right != nullptr)
    {
        searchTree(level + 1, root->right, lists);
    }
    if(root->left != nullptr)
    {
        searchTree(level + 1, root->left, lists);
    }
    return;
}

    

vector<vector<Node *>> depths(Node *root)
{
    int depth = 0;
    vector<vector<Node *>> list;
    vector<Node *>first;
    first.push_back(root);
    list.push_back(first);




};

    
