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


void pathSum(Node *head, int sum, int &numPaths, int pathValue=0){
    
    if(head == nullptr) {
        return;
    }
    pathValue += head->data;
    if(pathValue == sum) {
        ++numPaths;
    }

    pathSum(head->left, sum, pathValue, numPaths);
    pathSum(head->right, sum, pathValue, numPaths);

    return;
    
}

int main(void) {
    int numPaths;

    Node *a = new Node(4);
    a->left = new Node(7);
    a->right = new Node(7);

    pathSum(a, 11, numPaths);


    cout << numPaths << endl;
}





