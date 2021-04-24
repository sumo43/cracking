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

vector< vector< Node*> > searchTree(int level, Node *root, vector< vector< Node*> > lists) 
{

    if(level == lists.size()) lists.resize(level);
    
    vector<Node *> list = lists[level-1];
    if(root) list.push_back(root);
    else return;

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

    
int main(void)
{
    Node *root = new Node();
    vector< vector< Node *> > list;
    list = searchTree(0, root, list);

    for(vector<Node*> b: list) for(Node *a : b) if(a->data) cout << a->data;
}