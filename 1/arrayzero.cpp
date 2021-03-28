#include <iostream>
#include <string>
#include <vector>

//set row and column to zero


using namespace std;

int main(void)
{
    int **arr = new int*[5];
    vector<int> row;
    vector<int> col;

    for(int i = 0; i < 5; i++)
    {
        arr[i] = new int[5];
        for(int j = 0; j < 5; j++)
        {
            arr[i][j] = ((i == 2 && j == 2) || (i == 3 && j == 3)) ? 0 : 1;
            if(arr[i][j] == 0) row.push_back(j), col.push_back(i);
        }
    }



    while (row.size() != 0)
    {
        int r = row.back(), c = col.back();
        row.pop_back(), col.pop_back();

        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(i == c && j == r)
                {
                    for(int i = 0; i < 5; i++)
                    {
                        arr[i][r] = 0;
                        arr[c][i] = 0;
                    }
                }
            }
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
}