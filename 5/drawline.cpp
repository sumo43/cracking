#include <iostream>

using namespace std;


string binary(int num) {
    
    int a = 1;
    a = a << 7;
    string str;
    
    int ret = 0;

    for(int i = 0; i < 8; i++) {

        if(num & a) {
            str += "1";
        }
        else {
            str += "0";
        }

        a >>= 1;

    }

    return str;
}


using namespace std;

// number to add 1 to == 256 >> y, just subtract y after end of each "byte"

void printLine( char scr[] , int width, int size) {

    for(int i = 0; i < size; i++) {
        if(i != 0 && i % width == 0) {
            cout << endl;
        }
        cout << binary(scr[i]) << " ";
    }
    cout << endl;

}

char *drawLine( int size, char *scr, int width, int x1, int x2, int y) {


    // y // 8 is the number block, y % 8 is the bit we need to flip (1 << n-1)
    
    for(int i = 0; i < size / width; i++) {
        for(int j = 0; j < width; j++) {

            if(y / 8 == j && i >= x1 && i <= x2) {
                int a = 7 - (y % 8);
                scr[i * width + j] = 1;
                scr[i * width + j] <<= a;
            }
        }
    }

    printLine(scr, width, size);
}


int main(void) {

    int arrSize;
    int x1;
    int x2;
    int y;
    int width;

    cout << "print size, x1, x2, y" << endl;
    cin >> arrSize >> x1 >> x2 >> y >> width;

    char one[arrSize];
    for(int i = 0; i < arrSize; i++) {
        one[i] = 0;
    }
    int size = sizeof(one) / sizeof(one[0]);
    
    drawLine(size, one, width, x1, x2, y);
}

