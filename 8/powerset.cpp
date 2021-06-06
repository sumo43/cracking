#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

auto subsets(vector <int> set){

    if(set.size() == 1) {
        //return an empty set
        return vector<vector<int>>();
    }
    
    auto sub = vector<vector<int>>();

    for(int i = 0; i < set.size(); i++) {
        //add all subsets of this current set
        auto currentSubset = vector<int>();
        for(int j = 0; j < set.size(); j++) {
            if(j != i) {
                currentSubset.push_back(set[j]);
            }
        }

        sub.insert(sub.end(), currentSubset);

        auto n = subsets(currentSubset);
        for(int j = 0; j < n.size(); j++) {
            if(find(sub.begin(), sub.end(), n[j]) == sub.end()) {
                sub.insert(sub.end(), n[j]);
            }
        }
    }
    return sub;
}

int main(void) {


    vector<int> set{1,2,3,4,5};


    auto s = subsets(set);


    for(int i = 0; i < s.size(); i++) {
        for(int j = 0; j < s[i].size(); j++) {
            cout << s[i][j];
        }
        cout << endl;
    }


    

}

