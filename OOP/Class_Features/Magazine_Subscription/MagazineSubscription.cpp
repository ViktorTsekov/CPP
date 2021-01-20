#include "MagazineSubscription.h"

MagazineSubscription::MagazineSubscription(Person customer, Date startDate, Date expirationDate) {
    this->customer = customer;
    this->startDate = startDate;
    this->expirationDate = expirationDate;
}

void MagazineSubscription::displayCustomer() {
    customer.showCustomer();
    cout << "Start date: "; startDate.displayDate();
    cout << "Expiration date: "; expirationDate.displayDate();
}