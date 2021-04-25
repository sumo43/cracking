#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {};
};

bool subtree(Node *large, Node *small) {

    if(large == nullptr) {
        return true;
    }

    if(large->data != small->data) return false;

    return subtree(large->left, small->left) && subtree(large->right, small->right);
    
}

bool subtreeCheck(Node *large, Node *small) {
    
    if(large == nullptr) {
        return false;
    }
    
    bool one = false, two = false;
    if(large->data == small->data) {
        return subtree(large, small);
    }
    else
    {
        return subtreeCheck(large->left, small) || subtreeCheck(large->right, small);
    }

}

int main(void) {

    Node *a = new Node(4);
    a->left = new Node(5);
    a->right = new Node(6);

    Node *b = new Node(10);
    b->left = new Node(11);
    b->right = new Node(12);

    a->right->right = b;

    cout << subtreeCheck(a, b) << endl;
}

