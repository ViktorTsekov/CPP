#include "Inventory.h"

istream& operator>>(istream& in, Inventory& inventory) {
    cout << "Enter quantity: "; in >> inventory.quantity;
    cout << "Enter price: "; in >> inventory.individualPrice;

    return in;
}

Inventory::Inventory() {
    productNumber = 0;
    quantity = 0;
    individualPrice = 0;
}

void Inventory::setProductNumber(int num) {
    productNumber = num;
}

string Inventory::getLine() {
    string line = "#" + to_string(productNumber) + " " + to_string(quantity) + "*" + to_string(individualPrice);
    return line;
}