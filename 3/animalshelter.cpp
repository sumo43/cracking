#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include "util.h"
#include <string>

using namespace std;

class Animal
{
    public:
        string type;
        int num;
        Animal(string type, int num)
        {
            this->type = type;
            this->num = num;
        }

};


class Shelter
{
    public:
        vector<Animal *> shelter;
        int size;

        Shelter()
        {
            size = 0;
        }

        void enqueue(string type, int data)
        {
            shelter.push_back(new Animal(type, data));
        }

        Animal *dequeueAny()
        {
            Animal *a = shelter.at(0);
            shelter.erase(shelter.begin());
            return a;
        }

        Animal *dequeueDog()
        {
            for(int i = 0; i < shelter.size() - 1; i++)
            {
                string type = shelter.at(i)->type;
                if(type.compare("dog") == 0)
                {
                    Animal *a = shelter.at(i);
                    shelter.erase(shelter.begin() + i);
                    return a;
                }
            }
            
            return nullptr;
        }

        Animal *dequeueCat()
        {
            for(int i = 0; i < shelter.size(); i++)
            {
                string type = shelter.at(i)->type;
                if(type.compare("cat") == 0)
                {
                    Animal *a = shelter.at(i);
                    shelter.erase(shelter.begin() + i);
                    return a;
                }
            }
            return nullptr;
        }
};


int main(void)
{
    Shelter *s = new Shelter();

    s->enqueue("dog", 5);
    s->enqueue("dog", 4);
    s->enqueue("cat", 3);




    cout << s->dequeueAny()->num << endl;
    cout << s->dequeueCat()->num << endl;
}

