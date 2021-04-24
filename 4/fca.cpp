#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>
#include <unordered_map>

using namespace std;

//if98

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {};
};


int Contains(Node *head, Node *one, Node *two, Node* &found) {

    if(head == nullptr) return 0;
    if(head == one) {
        return 1;
    }
    else if(head == two) {
        return 2;
    }
    else {

        int numone = Contains(head->right, one, two, found);
        int numtwo = Contains(head->left, one, two, found);


        if((numone == 1 && numtwo == 2) || (numone == 2 && numtwo == 1)) {
            found = head;
            cout << found << endl;
            cout << head << endl;
            return 0;
        }
        else if(numone == 1 || numtwo == 1) {
            return 1;
        }
        else if(numone == 2 || numtwo == 2) { 
            return 2;
        }

    }
    return 0;

}


int main(void) {


    Node *head = new Node(1);
    head->right = new Node(2);
    head->left = new Node(3);
    head->right->right = new Node(50);
    head->right->left = new Node(100);
    head->left->right = new Node(7);
    head->left->left = new Node(8);
    Node *found = nullptr;
    Contains(head, head->right->right, head->right->left, found);
    cout << found->data << endl;
}
