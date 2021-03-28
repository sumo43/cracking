#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str;
    cin >> str;

    int *hash = new int[26];

    for(int i = 0; i < str.length(); i++)
    {   
        ++hash[str[i]];
        if(hash[str[i]] > 1)
        {
            cout << "not unique" << endl;
            return 1;
        }
    }

    cout << "unique" << endl;
    return 0;

}