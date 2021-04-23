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
        int data;
        Node *right;
        Node *left;
        Node(int data)
        {
            this->data = data;
        }
        Node()
        {
        }
};   

//projects a,c,b,d,e,f
//dependencies (a, d), (f, b), (b, d), (f, a), (d, c)
//
vector<string> buildOrder(vector<string> projects, vector<tuple<string, string>> order)
{
    vector<string> build;
    //make a hashmap of the builds
    unordered_map<string, string> map;
    unordered_map<string, bool> visited;

    for(int i = 0; i < projects.size(); i++)
    {
        map[projects[i]] = nullptr;
        visited[projects[i]];
    }

    for(int i = 0; i < order.size(); i++)
    {
        tuple<string, string> a = order[i];
        map[get<0>(a)] = get<1>(a);
    }

    for(int i = 0; i < projects.size(); i++)
    {
        string s = map[projects[i]];
        if(s != nullptr)
        {
            build.push_back(projects[i]);
        }
    }





};




