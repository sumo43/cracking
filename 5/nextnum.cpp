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

int smallestZeroPos(string m) {
    // finds if there are two bits (1,0)
    int pos = -1;
    for(int i = 0; i < m.length() - 1; i++) {
        if(m[i] == '1' && m[i+1] == '0') {
            pos = 31 - i;
        }
    }
    return pos;

}


int smallestZeroPos2(string m) {
    int pos = -1;
    for(int i = 0; i < m.length() - 1; i++) {
        if(m[i] == '0' && m[i+1] == '1') {
            pos = 31 - i;
        }
    }

    return pos;
}

int main(void) {
    //find the smallest zero
    //edge case of solid block of 1s until the end: no smaller, 
    //bigger = right shift

    int num = 62;
    string num_bin = binary(num);


    cout << num_bin << endl;


    
    //swap tint he two values to get the biggest
    int p1;

    int pos = smallestZeroPos2(num_bin);
    if(pos != -1) {
        

        p1 = 1 << (pos - 1);
        int biggest = (num | p1) ^ (p1 >> 1);
        cout << binary(biggest) << endl;
    }



    pos = smallestZeroPos(num_bin);

    if(pos != -1) {

        p1 = 1 << (pos - 1);
        int smallest = (num ^ p1) | (p1 >> 1);
        cout << binary(smallest) << endl;
    }

}

