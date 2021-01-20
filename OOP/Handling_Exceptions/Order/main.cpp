#include "Order.h"

static void initialize(Order&);

int main() {
    Order order;

    initialize(order);
    cout << order;
}

static void initialize(Order& order) {
    Exception exception;

    try {
        cin >> order;
    } catch(Exception& e) {
        e.getErrorDetails();
        cout << "\nPlease enter valid value:\n";
        initialize(order);
    }
}