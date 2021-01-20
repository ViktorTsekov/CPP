#include "Order.h"

ostream& operator<<(ostream& out, const Order& order) {
    out << endl;
    out << "Order number: " << order.orderNumber << endl;
    out << "Quantity ordered: " << order.quantityOrdered << endl;
    out << "Single price: " << order.singlePrice << endl;
    out << "Total price: " << order.totalPrice << endl;

    return out;
}

istream& operator>>(istream& in, Order& order) {
    Exception e;
    double input;
    string strInput;

    //Order number
    cout << endl;
    cout << "Enter order number: "; cin >> strInput;
    if(e.checkIfValueIsOutOfRange(strInput, 1, 4, e)) {
        throw(e);
    } else {
        order.orderNumber = strInput;
    }

    //Quantity
    cout << "Enter quantity: "; cin >> input;
    if(e.checkIfValueIsMismatched(input, e)) {
        throw(e);
    } else if(e.checkIfValueIsOutOfRange(input, 1, 50, e)){
        throw(e);
    } else {
        order.quantityOrdered = input;
    }

    //Single price
    cout << "Enter single price: "; cin >> input;
    if(e.checkIfValueIsMismatched(input, e)) {
        throw(e);
    } else if(e.checkIfValueIsOutOfRange(input, 1, 39.95, e)){
        throw(e);
    } else {
        order.singlePrice = input;
    }

    //Total price
    input = order.quantityOrdered * order.singlePrice;

    if(e.checkIfValueIsOutOfRange(input, 0, 1000, e)) {
        throw(e);
    } else {
        order.totalPrice =  input;
    }

    return in;
}

Order::Order() {
    orderNumber = "/";
    quantityOrdered = 0;
    singlePrice = 0;
    totalPrice = 0;
}