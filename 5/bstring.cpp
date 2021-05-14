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

    double test = 0.72;

    while(test / (int) test != 1) {
        test *= 10;
    }

    binary(test);

}





