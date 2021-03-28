#include <iostream>
#include <string>
#include <vector>

//check if str2 is a rotation of str1
//assume that you have issubstring

using namespace std;

int main(void)
{
    string str1;
    string str2;
    cin >> str1;
    cin >> str2;

    str2 += str2;

    int num = str2.find(str1);

    if(num > -1)
    {
        cout << "is rotation" << endl;
        return 0;
    }

    cout << "is not rotation" << endl;
    return 1;
}