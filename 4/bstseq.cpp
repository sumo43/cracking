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

vector<vector<int>> sequences(Node *head) {

    if(head->left == nullptr && head->right == nullptr) {
        return {{head->data}};
    }

    vector<vector<int>> left = sequences(head->left);
    vector<vector<int>> right = sequences(head->right);

    vector<vector<int>> fin;
    
    //make a vector of (l + r) + (r + l)
    vector<vector<int>> pos1 = left;
    for(vector<int> i : pos1) {
        i.insert(i.begin(), head->data);
        for(vector<int> j : right) {
            vector<int> a = i;
            a.insert(a.end(), j.begin(), j.end());
            fin.push_back(a);
        }
    }

    vector<vector<int>> pos2 = right;
    for(vector<int> i : pos2) {
        i.insert(i.begin(), head->data);
        for(vector<int> j : left) {
            vector<int> a = i;
            a.insert(a.end(), j.begin(), j.end());
            fin.push_back(a);
        }
    }
    
    return fin;
}

int main(void) {
    
    Node *head = new Node(1);
    head->left = new Node(3);
    head->left->right = new Node(4);
    head->left->left = new Node(5);
    head->right = new Node(2);

    vector<vector<int>> seq = sequences(head);

    for (vector<int> s : seq) {
        for(int a : s) cout << a;
        cout << endl;
    }

}
