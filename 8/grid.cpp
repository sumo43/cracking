#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

//where robot wants to be
const int h = 5;
const int w = 5;

vector<char> search(int y, int x, vector<char> path, int **map) {

    
    if (y == h-1 && x == w-1) {
        vector<char> v = vector<char>('f');
        return v;
    }

    if(x >= w || y >= h) {
        return vector<char>();
    } 

    if(map[y][x] == 1) {
        return vector<char>();
    }

    vector<char> right = search(y, x+1, path, map);
    vector<char> bottom = search(y+1, x, path, map);
   
    if(right.size() != 0 && bottom.size() == 0) {
        right.insert(right.begin(), 'r'); 
        return right;
    }
    else if(right.size() == 0 && bottom.size() != 0) {
        bottom.insert(bottom.begin(), 'b');
        return bottom;
    } 
    else if(right.size() != 0 && bottom.size() != 0) {

        if(bottom.size() <= right.size()) {
            bottom.insert(path.begin(), 'b');
            return bottom;
        }
        else if(right.size() < bottom.size()) {
            right.insert(path.begin(), 'r');
            return right;
        }
    }
}




int main(void) {

    int y = 0;
    int x = 0;


    //init map
    int **map;
    map = new int *[h];
    for(int i = 0; i < h; i++) {
        map[i] = new int[w];
        for(int j = 0; j < w; j++) {
            map[i][j] = 0;
        }
    }

    vector<char> solved = search(0, 0, vector<char>(), map);

    for(int i = 0; i < solved.size(); i++) {
        cout << solved.at(i) << endl;
    }

}

