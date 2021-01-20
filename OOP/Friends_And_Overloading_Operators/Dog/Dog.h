#ifndef DOG
#define DOG

#include <iostream>
#include <string.h>

using namespace std;

class Dog {
    friend ostream& operator<<(ostream&, const Dog&);
    friend istream& operator>>(istream&, Dog&);

    private:
        string breed;
        string eyeColor;

    public:
        Dog operator*(Dog&);

};

#endif