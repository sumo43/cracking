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

int onelen(string m) {

    int maxlen = 0;
    int currentLen = 0;

    for(int i = 0; i < m.length(); i++) {
        if(m[i] == '1') {
            currentLen += 1;
        }
        else if(m[i] == '0') {
            if(currentLen > maxlen) {
                maxlen = currentLen;
            }
            currentLen = 0;
        }


    }

    if(currentLen > maxlen) {
        maxlen = currentLen;
    }

    return maxlen; 
        
}

int main(void) {

    int maxLen = 0;
    int currentLen = 0;

    int num = 7;
    string num_str = binary(num);

    int mask = 1;

    currentLen = onelen(num_str);
    maxLen = currentLen;

    for(int i = 0; i < num_str.length(); i++) {
            currentLen = onelen(binary(num | mask));
            if(currentLen > maxLen) {
                maxLen = currentLen;
            }

        mask <<= 1;
        
    }

    cout << maxLen << endl;

}






