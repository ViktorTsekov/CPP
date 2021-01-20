#include "House.h"

House::House(string address, int sqFeet) {
    streetAddress = address;
    squareFeet = sqFeet;
}

void House::displayHouse() {
    cout << "Address: " << streetAddress << endl;
    cout << "Size in square feet: " << squareFeet << endl;
}