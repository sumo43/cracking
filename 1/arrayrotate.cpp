#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int **arr = new int*[5];
    int **temp = new int*[5];
    for(int i = 0; i < 5; i++)
    {
        arr[i] = new int[5];
        for(int j = 0; j < 5; j++)
        {
            if(i % 2 == 0)
            {
                arr[i][j] = 0;
            }
            else
            {
                arr[i][j] = 1;
            }

            cout << arr[i][j];
        }

        cout << endl;
    }

    for(int i = 0; i < 5; i++)
    {
        temp[i] = new int[5];
    }


    for(int i = 0; i < 5; i++)
    {
        
        for(int j = 0; j < 5; j++)
        {
            temp[i][j] = arr[j][i];

        }
        cout << endl;
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << temp[i][j];
        }
        cout << endl;
    }



}