#include <iostream>
using namespace std;

class Root 
{
    public:
        virtual void print()
        {
            cout << "I am from root\n";
        }
};

class Child1: public Root
{
    public:
        void print()
        {
            cout << "From child 1\n";
        }
};

class Child2: public Child1
{
    public:
        void print()
        {
            cout << "From child 2\n";
        }
};

int main(int argc, char const *argv[])
{
    Root *pchild = new Child2();
    pchild->print();
    return 0;
}
