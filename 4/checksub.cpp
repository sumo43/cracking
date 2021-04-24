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

bool subtree(Node *head, Node* sub) {
    if(head == nullptr) {
        return true;
    }
    else {
        if(head == sub) {
            bool left = subtree(head->left, sub->left);
            bool right = subtree(head->right, sub->right);

            if(left && right) {
                return true;
            }
        }
        else return false;
    }
}

bool subtreeCheck(Node *large, Node *small) {
    
    if(large == nullptr) {
        return false;
    }
    else if(subtree(large, small)) return true;
    else {
        return subtree(large->left, small) || subtree(large->right, small);
    }
}

int main(void) {

        

}

