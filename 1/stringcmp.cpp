#include <iostream>
#include <string>

using namespace std;

int main()
{

    string one;
    cin >> one;

    string newString = "";
    int count = 0;

    for(int i = 1; i < one.length(); i++)
    {
        count++;

        if(one[i - 1] != one[i])
        {
            if(count > 1)
            {
                newString.append(to_string(count));
            }
            newString += one[i-1];
            count = 0;
        }
        if(i == one.length() - 1)
        {
            if(count > 1)
            {
                newString.append(to_string(count+1));
            }
            newString += one[i];
            count = 0;
        }

    }

    cout << newString << endl;
}