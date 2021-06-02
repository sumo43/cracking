#include <cstdlib>
#include <iostream>

using namespace std;

int steps(int count) {

    if(count == 0) {
        return 0;
    }
    if(count == 1) {
        return 1;
    }
    else if(count == 2) {
        return 2;
    }
    else{
        return 1 * steps(count - 1) + 2 * steps(count - 2) + 3 * steps(count - 3);
    }

}


int main(void) {
    cout << "enter number of steps" << endl;
    int numSteps;
    cin >> numSteps;

    cout << steps(numSteps) << endl;
     
     
}

