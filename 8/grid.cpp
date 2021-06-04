#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

const int h = 5;
const int w = 5;

vector<char> * recursiveBFS(int loc1, int loc2, int **board, vector<char> *path, int pathLength) {


    if(loc1 == 4 && loc2 == 4) {
        *path = vector<char> (); 
        return path;
    }
    else if(loc1 >= 5 || loc2 >= 5) {
        return nullptr;
    }
    else if(board[loc1][loc2] == 1) {
        return nullptr;
    }
    else {

        vector<char> * right = recursiveBFS(loc1, loc2 + 1, board, path, pathLength + 1); 
        vector<char> * bottom = recursiveBFS(loc1 + 1, loc2, board, path, pathLength + 1);

        if(right == nullptr && bottom == nullptr) {
            return nullptr;
        }
        else if(right == nullptr) {
            bottom->insert(bottom->begin(), 'b');
            return bottom;
        }
        else if(bottom == nullptr) {
            right->insert(right->begin(), 'r');
            return right;
        }
        else if(right->size() >= bottom->size()) {
            bottom->insert(bottom->begin(), 'b');
            return bottom;
        }
        else if(right->size() < bottom->size()) {
            right->insert(right->begin(), 'r');
            return right;
        }

    }

}

int main(void) {
    
    int y = 0;
    int x = 0;

    //init map
    int **map = new int *[h];
    for(int i = 0; i < h; i++) {
        map[i] = new int[w];
        for(int j = 0; j < w; j++) {
            map[i][j] = 0;
        }
    }

    map[2][0] = 1;
    map[3][1] = 1;
    map[4][2] = 1;
    map[0][1] = 1;
    map[1][2] = 1;
    map[2][3] = 1;
    map[3][4] = 1;
    
    vector<char> *path = new vector<char>(); 

    path = recursiveBFS(0,0,map,path,0);
    for(int i = 0; i < path->size(); i++) {
        cout << path->at(i) << endl;
    }
}

