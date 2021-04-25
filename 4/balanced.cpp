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

int getHeight(Node *head, bool &isBalanced) {
   
    if(!head->left && !head->right) {
        return 1;
    }
    else if(!head->left) {
        if(getHeight(head->right, isBalanced) > 1) {
            isBalanced = false;
            return getHeight(head->right, isBalanced);
        }
    }
    else if(!head->right) {
        if(getHeight(head->left, isBalanced) > 1) {
            isBalanced = false;
            return getHeight(head->left, isBalanced);
        }
    }

    if(abs(getHeight(head->left, isBalanced) - getHeight(head->right, isBalanced)) > 1) {
        isBalanced = false;
    }

    int l = 1 + getHeight(head->left, isBalanced);
    int r = 1 + getHeight(head->right, isBalanced);

    if(l >= r) return l;
    else return r;
}

int main(void) {
    bool isBalanced = true;

    Node *head = new Node(1);

    head->right = new Node(2);
    head->right->right = new Node(6);
    head->right->left = new Node(7);


    head->left = new Node(3);
    head->left->right = new Node(2);
    head->left->left = new Node(3);

    getHeight(head, isBalanced);
    cout << isBalanced << endl;
}



