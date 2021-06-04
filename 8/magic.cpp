#include <cstdlib>
#include <iostream>



using namespace std;

int magicIndex(int arr[], int left, int right) {
    
    if(right == left) {
        if(arr[right] == right) {
            return right;
        }
        else {
            return -1;
        }
    }
    
    int mid = (left + right) / 2;

    if(arr[mid] == mid) {
        return mid;
    }
    else {
        
        int leftArray = magicIndex(arr, left, mid);
        int rightArray = magicIndex(arr, mid + 1, right);
        
        if(leftArray != -1) {
            return leftArray;
        }
        else if(rightArray != -1) {
            return rightArray;
        }
        else {
            return -1;
        }
    }
};


int main(void) {


    int arr [] = {1,3,4,5,5,6,7,9,10,10,10,10};

    int magic = magicIndex(arr, 0, 11);

    cout << magic << endl;




}

