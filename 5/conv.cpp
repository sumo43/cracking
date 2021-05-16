#include <iostream>

using namespace std;



string binary(int num) {
    
    int a = 1;
    a = a << 30;
    string str;
    
    int ret = 0;

    for(int i = 0; i < 31; i++) {

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

int main(void) {
    

    int one = 29;
    int two = 15;

    int x = one ^ two;


    int a = 0;

    int b = 1;

    for(int i = 0 ; i < 30; i++) {
        if((b & x) != 0) {
            a++;
        }
        b <<= 1;
    }

    cout << a << endl;
}




    
