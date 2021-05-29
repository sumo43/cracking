#include <cstdlib>
#include <iostream>
#include <vector>
#include <random>
#include <tuple>
#include <string>

using namespace std;

// 0 means it's hidden, 1 means there's secretly a bomb, 2 is empty, 3 is marker

class Minesweeper {


    public:
    
    //board state of 0 is hidden, 1 is not, 2 is marker

    int **board;
    int **boardState;
    int size;

    // possible states for the board, each represented by a symbol in pprint
    int empty = 0;
    int bomb = -1;

    int bombCount;

    int spaceCount;

    default_random_engine generator;
    uniform_int_distribution<int> distro;

    Minesweeper() {
        cout << "Print size of board" << endl;
        cin >> this->size;
        cout << "Print bomb count" << endl;
        cin >> this->bombCount;

        board = new int*[size];
        boardState = new int*[size];

        for(int i = 0; i < size; i++) {
            board[i] = new int[size];
            boardState[i] = new int[size];
            for(int j = 0; j < size; j++) {
                board[i][j] = 0;
                boardState[i][j] = 0;
            }
        }

        distro = uniform_int_distribution<int>(0, size-1);
        int y;
        int x;

        for(int i = 0; i < bombCount; i++) {

            do {
                y = distro(generator);
                x = distro(generator);
            }
            while(board[y][x] == -1);
            board[y][x] = -1;
            
        }

        this->calcDists();
        int i = this->game();



    }

    void calcDists() {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {

                board[i][j] = kernel(i, j);
            }
        }
    }


    int kernel(int i, int j) {
        int a = 0;
        if(board[i][j] == -1) {
            return -1;
        }

        for(int k = -1; k < 2; k++) {
            for(int l = -1; l < 2; l++) {
                if(i + k >= 0 && i + k < size && j + l >= 0 && j + l < size) {
                    if(board[i + k][j + l] == -1) {
                        a++;
                    }

                }
            }
        }
        return a;
    }

    int game() {

        while(true) {

            this->pprint();

            bool marker = false;

            cout << "Do you want to place a marker? (y/n)" << endl;
            char a;
            cin >> a;
            if(a == 'y') {
                marker = true;
            }
            else marker = false;

            cout << "Pick your next move:" << endl;
            cout << "Print column and row" << endl;
            int y;
            int x;
            cin >> y >> x;

            while(boardState[y][x] == 1) {
                cout << "Invalid move" << endl;
                cout << "Print column and row" << endl;
                cin >> y >> x;
            }


            if(board[y][x] == -1) {
                cout << "You lose" << endl;
                return 1;
            }
            else {
                if(marker) {
                    boardState[y][x] = 2;
                }
                else {
                    boardState[y][x] = 1;

                }

                spaceCount--;
                if(spaceCount == bombCount) {
                    cout << "You win" << endl;
                    return 0;
                }



            }
        }
    }

    void pprint() {

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                if(boardState[i][j] == 1) {
                    cout << board[i][j];
                }
                else {
                    if(boardState[i][j] == 2) {
                        cout << '?';
                    }
                    else {
                        cout << '_';
                    }
                
                }
                cout << " ";
                
            }
            cout << endl;
        }
    }

};




int main(void) {


    Minesweeper *sweeper = new Minesweeper();

}


    
