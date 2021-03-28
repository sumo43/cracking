#include <iostream>
#include <string>

using namespace std;

int main()
{
    string url;
    getline(cin, url);
    int strlen = url.length();

    for(int i = 0; i < strlen; i++)
    {
        if(url[i] == ' ')
        {
            for(int j = strlen - 1; j > i; j--)
            {
                url[j] = url[j-1];
            }
            for(int k = strlen - 1; k > i + 1; k--)
            {
                url[k] = url[k-1];
            }
            url[i] = '%';
            url[i+1] = '2';
            url[i+2] = '0';
            i += 3;
        }
    }

    cout << url << endl;
}