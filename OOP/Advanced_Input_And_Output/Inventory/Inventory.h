#ifndef INVENTORY
#define INVENTORY

#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

class Inventory{
    friend istream& operator>>(istream&, Inventory&);

    private:
        int productNumber;
        int quantity;
        double individualPrice;

    public:
        Inventory();
        void setProductNumber(int);
        string getLine();
};

#endif