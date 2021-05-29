#include <algorithm>
#include <cstdlib>
#include <iostream>


using namespace std;


template<class T>
class Node {

    public:

    T data;
    Node *next;

    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
};
        

template<class T>
class circularArray {

    public:

    T *begin();

    bool is_full;
    int size;
    T *arr;
    int index;
     

    circularArray(int size) {
        arr = new T[size];
        this->size = size;
        index = 0;
    }


    T get(int i) {
        return arr[(index + i) % size];
    }

    void set(int in, T i) {
        arr[in] = i;
    }

    void pprint() {
        for(int i = 0; i < size; i++) {
            cout << arr[(index + i) % size] << endl;
        }
    }

    void rotate(int rot) {
        index += rot;
        index %= size;
    }

};



int main(void) {

    circularArray<int> circ(5);
    
    for(int i = 0; i < 5; i++) {
        circ.set(i, i);
    }

    circ.pprint();
    circ.rotate(5);
    circ.pprint();
}






