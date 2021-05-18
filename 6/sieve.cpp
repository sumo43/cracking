//Sieve of Eratosthenes algorithm for making list of primes
#include <iostream>
#include <vector>
#include <cmath>


using namespace std;


void crossOff(vector<bool> &flags, int prime) {

    for(int i = prime * prime; i < flags.size(); i++) {
        if(i % prime == 0) {
            flags[i] = false;
        }
    }
}




int getNextPrime(vector<bool> flags, int prime) {

    for(int i = prime + 1; i < flags.size(); i++) {
        if(flags[i] == true) {
            return i;
        }
    }
}
    
vector<bool> sieve(int max) {
    vector<bool> flags(max + 1, true);
    flags[0] = false;
    flags[1] = false;

    int count = 0;
    int prime = 2;

    while(prime <= sqrt(max)) {
        crossOff(flags, prime);
        prime = getNextPrime(flags, prime);
    }

    return flags;

}

int main(void) {

    int max = 20;
    vector<bool> s = sieve(max);

    for(int i = 0; i < s.size(); i++) {
        if(s[i]) {
            cout << i << endl;
        }
    }
}



