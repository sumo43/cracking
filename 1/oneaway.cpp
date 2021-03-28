#include <iostream>
#include <string>

using namespace std;

int main()
{

    string one;
    string two;
    getline(cin, one);
    getline(cin, two);
    int len1 = one.length();
    int len2 = two.length();

    int away = 0;

    int larger = 0;

    if(len1 >= len2)
    {
        for(int i = 0; i < len1; i++)
        {   
            if(one[larger] != two[i])
            {
                if(one[larger+1] == two[i])
                {
                    away++;
                    larger++;
                }
                else
                {
                    away++;
                }
                
            }

            larger++;
            
        }

    }
    else if(len2 > len1)
    {
        for(int i = 0; i < len2; i++)
        {   
            if(two[larger] != one[i])
            {
                if(two[larger+1] == one[i])
                {
                    away++;
                    larger++;
                }
                else
                {
                    away++;
                }
                
            }

            larger++;
            
        }

    }

    if(away == 1)
    {
        cout << "true" << endl;
        return 0;
    }
    cout << "false" << endl;
    return 1;



}