#include <cstdlib>
#include <iostream>


using namespace std;


int multiply(int num, int count) {
    
    if(count == 0) {
        return num;
    }

    cout << count;
    
    return num + multiply(num, count - 1);
}




int main(void) {
    

    cout << 'a' << endl;




    cout << multiply(5, 5) << endl; 
}

