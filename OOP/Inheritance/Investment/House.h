#ifndef HOUSE
#define HOUSE

#include <iostream>
#include <string.h>

using namespace std;

class House {
    private:
        string streetAddress;
        int squareFeet;

    public:
        House(string = "", int = 0);
        void displayHouse();
};

#endif