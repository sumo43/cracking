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


    int num = 1775;

    cout << binary(num) << endl;

    int a = 1;

    for(int i = 0; i < 14; i ++) {

        if(!(num & a<<1) && (num & a)) {
            num += a<<1;
            num -= a;
        }
        else if((num & a<<1) && !(num & a)) {
            num += a;
            num -= a<<1;
        }
        a = a<<2;
    }

    cout << binary(num) << endl;


}





