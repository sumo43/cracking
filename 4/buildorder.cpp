#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>
#include <unordered_map>

using namespace std;

//if98

class Node
{
    public:
        char data;
        bool seen = false;
        bool resolved = false;
        vector<Node *>edges;
        Node(int data) : data(data) {};
        void visited() {seen = true;}
};   

//projects a,c,b,d,e,f
//dependencies (a, d), (f, b), (b, d), (f, a), (d, c)

bool checkDependency(Node *root, vector<char> *projectOrder) {
    
    if(root->seen == true) return 1;
    root->visited();

    for(Node *edge : root->edges) {
        if(find(projectOrder->begin(), projectOrder->end(), edge->data) == projectOrder->end()) {
            if(edge->seen) {
                cout << "loop detected";
                return 2;
            }
        }
        checkDependency(edge, projectOrder);
    }

    projectOrder->push_back(root->data);
    
    return 1;
}

// if we represent the dependencies as a graph, w/ path from each project to its dependency
// the order is the traversal order of the graph, reversed
// use seen to avoid cycles
//projects a,c,b,d,e,f
//dependencies (a, d), (f, b), (b, d), (f, a), (d, c)


int main(void) {
    
    vector<char> projectOrder;
    vector<Node *>start;
    Node *a = new Node('a');
    Node *b = new Node('b');
    Node *c = new Node('c');
    Node *d = new Node('d');
    Node *e = new Node('e');
    Node *f = new Node('f');

    a->edges.push_back(f);
    d->edges.push_back(a);
    b->edges.push_back(f);
    d->edges.push_back(b);
    c->edges.push_back(d);

    start = {a,b,c,d,e,f};
    for(Node *startingNode : start) {
        checkDependency(startingNode, &projectOrder);
    }

    for(char b : projectOrder) {
        cout << b << endl;
    }

}



