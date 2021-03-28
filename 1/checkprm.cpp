#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string one;
    string two;

    cin >> one;
    cin >> two;

    int *hash = new int[26];

    for(int i = 0; i < 26; i++)
    {
        hash[i] = 0;
    }


    for(int i = 0; i < one.length(); i++)
    {
        hash[one[i] - 97]++;
        
    }

    for(int i = 0; i < two.length(); i++)
    {
        hash[two[i] - 97]--;
    }

    for(int i = 0; i < 26; i++)
    {
        if(hash[i] != 0)
        {
            
            cout << "not permutation" << endl;
            return 1;
        }
    }

    cout << "permutation" << endl;
    return 0;
}