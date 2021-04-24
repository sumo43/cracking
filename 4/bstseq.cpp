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
        vector<int> vec;
        vec.push_back(head->data);
        vector<vector<int>> vec2;
        vec2.push_back(vec);
        return vec2;
    }

    vector<vector<int>> vec1 = sequences(head->right);
    vector<vector<int>> vec2 = sequences(head->left);

    vector<vector<int>> a = vec1;
    a.insert(a.end(), vec2.begin(), vec2.end());
    vector<vector<int>> b = vec2;
    b.insert(b.end(), vec1.begin(), vec1.end());
    
    a.insert(a.end(), b.begin(), b.end());
    return a;

}


int main(void) {
    
    Node *head = new Node(1);
    head->left = new Node(3);
    head->right = new Node(2);

    vector<vector<int>> seq = sequences(head);

    for(vector<int> vec : seq) {
        for(int i : vec) {
            cout << i;
        }
        cout << endl;
    }



}
