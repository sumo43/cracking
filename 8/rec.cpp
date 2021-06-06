#include <cstdlib>
#include <iostream>


using namespace std;


int multiply(int num, int count) {
    
    if(count == 1) {
        return num;
    }

    
    return num + multiply(num, count - 1);
}




int main(void) {

    int num1;
    int num2;
    cin >> num1 >> num2;
    

    cout << multiply(num1, num2) << endl; 
}

