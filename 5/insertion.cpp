#include <iostream>

using namespace std;


void binary(int num) {
    
    int a = 1;
    a = a << 30;
    
    int ret = 0;

    for(int i = 0; i < 31; i++) {

        if(num & a) {
            cout << 1;
        }
        else {
            cout << 0;
        }

        a >>= 1;

    }
    cout << endl;
}




int main(void) {

    int N = 1024;
    int M = 19;

    int i = 2;
    int j = 6;

    M <<= i;
    int a = N | M;

    binary(a);

}


