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
        if (arr[mid] > mid) {
            int leftArray = magicIndex(arr, left, mid);
            return leftArray;
        }
        else if (arr[mid] < mid) {
            int rightArray = magicIndex(arr, mid + 1, right);
            return rightArray;
        }
    }
};

int magicIndexNotDistinct(int arr[], int left, int right) {
    
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
        if (arr[mid] <  mid) {
            int leftArray = magicIndexNotDistinct(arr, left, mid);
            return leftArray;
        }
        else if (arr[mid] > mid) {
            int rightArray = magicIndexNotDistinct(arr, mid + 1, right);
            return rightArray;
        }
    }
};



int main(void) {

    int arr2[] = {1, 3, 4, 5, 6, 6, 6};


    // with a non-distinct array, there are 2 possible cases:
    // either it skips a number, and therefore is too big for its index and "compensates" later on with repeating numbers
    // as in arr2, or it starts too small and "compensates" later with repeating numbers
    // we need to test both cases. runtime is still O(log(n))

    cout << magicIndexNotDistinct(arr2, 0, 6) << endl;
    cout << magicIndex(arr2, 0, 6) << endl;

}

