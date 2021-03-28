#include <iostream>
#include <string>

using namespace std;

int main()
{

    string str;
    getline(cin, str);
    int *hash = new int[26];

    for(int i = 0; i < 26; i++)
    {
        hash[i] = 0;
    }
    
    for(int i = 0; i < str.length(); i++)
    {
        hash[str[i] - 97]++;   
    }

    

    int ones = 0;

    for(int i = 0; i < 26; i++)
    {
        if(hash[i] % 2 != 0)
        {
            if(ones == 1)
            {
                cout << "not permutation of palindrome" << endl;
                return 0;
            }
            else if(ones == 0)
            {
                ones++;
            }
        }
    }

    cout << "permutation of palindrome" << endl;
    return 1;
}