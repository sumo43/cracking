#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <random>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {};
};
void pickRandom(Node *head, Node *&n, int node, int count=0) {

    if(head == nullptr) {
        return;
    }

    else if(count == node) {
        n = head;
        return;
    }

    pickRandom(head->left, n, node, count + 1);
    pickRandom(head->right, n, node, count + 1);
}

Node *getRandomNode(Node *head) {


    //measure depth
    Node *runner = head;
    int val = 0;
    while(runner != nullptr) {
        runner = runner->left;
        val++;
    }

    //assumes that the tree has 2^n - 1 possible nodes
    int possibleNodes = (int) pow(2, val) - 1;
    
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, possibleNodes - 1);
    
    int node = distribution(generator);
    
    Node *n;
    pickRandom(n, node);




}


int main(void) {



    

}


