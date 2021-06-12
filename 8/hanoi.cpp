#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

void pprint(stack<int>left, stack<int>middle, stack<int>right) {

    cout << "left" << endl;
    int lSize = left.size();
    int mSize = middle.size();
    int rSize = right.size();

    for(int i = 0; i < lSize; i++) {
        cout << left.top() << endl;
        left.pop();

    }
    cout << "middle" << endl;
    for(int i = 0; i < mSize; i++) {
        cout << middle.top() << endl;
        middle.pop();

    }
    cout << "right" << endl;
    for(int i = 0; i < rSize; i++) {
        cout << right.top() << endl;
        right.pop();
    }
}


void hanoi(int n, stack<int> &left, stack<int> &middle, stack<int> &right) {

    //solution for l=1
    if(n == 1) {
        right.push(left.top());
        left.pop();
    }
    else {
        //move all pieces above to middle
        hanoi(n - 1, left, right, middle);
        right.push(left.top());
        left.pop();
        hanoi(n - 1, middle, left, right);
    }
}

int main(void) {
    
    cout << "Enter number of disks" << endl;
    int disks;
    cin >> disks;
    
    auto left = stack<int>();
    auto middle = stack<int>();
    auto right = stack<int>();
    
    for(int i = disks; i > 0; i--) {
        left.push(i);
    }

    pprint(left, middle, right);

    hanoi(disks, left, middle, right);

    pprint(left, middle, right);


}

