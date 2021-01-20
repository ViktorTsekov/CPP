#ifndef ORDER
#define ORDER

#include <iostream>
#include <string.h>

#include "Exception.h"

using namespace std;

class Order {
    friend ostream& operator<<(ostream&, const Order&);
    friend istream& operator>>(istream&, Order&);

    private:
        string orderNumber;
        int quantityOrdered;
        double singlePrice;
        double totalPrice;

    public:
        Order();
};

#endif