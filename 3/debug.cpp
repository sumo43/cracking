#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include "stackplates.cpp"


using namespace std;



int main(void)
{

    sPlates *plates = new sPlates();

    for(int i = 0; i < 10; i++)
    {
        plates->push(i);
    }


    for(int i = 0; i < 11; i++)
    {
        cout << plates->pop() << endl;

    }


}

