#include <cstdlib>
#include <string>
#include <iostream>


using namespace std;
//hash table only accepts char *
int hashFunc(const char *str)
{
    int hash = 100;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    hash %= 100;
    return hash;
}


class Node {

    public:
    const char *data;
    Node *next;

    Node(const char *data) {
        this->data = data;
        this->next = nullptr;
    }
    Node() {
    }

};


class hashTable {

    public:


    Node **table;
    int size;

    hashTable(int size) {
        this->table = new Node *[size];
        this->size = size;
    }
    
    
    void add(const char *value) {
        int h = hashFunc(value);
        if(table[h] == nullptr) {
            table[h] = new Node(value);
        }
        else {
            cout << "a" << endl;
            Node *ptr = table[h];
            while(ptr->next != nullptr) {
                ptr = ptr->next;
            }
            ptr->next = new Node(value);
        }

    }

    void pprint() {
        for(int i = 0; i < size; i++) {
            if(table[i] != nullptr) {
                Node *ptr = table[i];
                cout << "hash " << i << " " << ptr->data << endl;
                while(ptr->next != nullptr) {
                    ptr = ptr->next;
                    cout << "hash " << i << " " << ptr->data << endl;
                }
            }
            else {
                cout << "hash " << i << " nullptr" << endl;
            }

        }
    }

};

int main(void) {
    
    hashTable *table = new hashTable(100);
    const char *hash;
    string input;

    for(int i = 0; i < 20; i++) {
        cout << "print string to hash" << endl;
        cin >> input;

        hash = input.c_str();

        table->add(hash);
        table->pprint();
    }

    table->pprint();
}




