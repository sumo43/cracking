#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node
{
    public:
    int data;
    vector<Node *>neighbors;
    bool visited = false;
    Node(int data)
    {
        this->data = data;
    }


};
/**
 3    1         10  11 
    4   5    6    7   8 
 2    0         9   12 
 */
    

bool search(Node *root1, Node *root2)
{

    queue<Node *> queue1;
    queue<Node *> queue2; 

    root1->visited = true, root2->visited = true;      

    queue1.push(root1), queue2.push(root2);

    while(!queue1.empty() && !queue2.empty())
    {
        Node *r1 = queue1.back();
        Node *r2 = queue2.back();
        queue1.pop(), queue2.pop();

        vector<Node *> nei1 = r1->neighbors;
        vector<Node *> nei2 = r2->neighbors;

        for(int i = 0; i < nei1.size(); i++)
        {
            queue1.push(nei1.at(i));
        }
            



    }


}

int main(void)
{
    Node *one = new Node(4);
    Node *two = new Node(7);


    Node *six = new Node(6);

    one->neighbors.push_back(new Node(3));
    one->neighbors.push_back(new Node(2));
    one->neighbors.push_back(new Node(1));
    one->neighbors.push_back(new Node(0)); 
    one->neighbors.push_back(six);

    Node *five = new Node(5);
    five->neighbors.push_back(six);
    two->neighbors.push_back(six);
    two->neighbors.push_back(new Node(10));
    two->neighbors.push_back(new Node(11));
    two->neighbors.push_back(new Node(12));
    two->neighbors.push_back(new Node(9));
    two->neighbors.push_back(new Node(8));

    search_connection(one, two);
    
}


