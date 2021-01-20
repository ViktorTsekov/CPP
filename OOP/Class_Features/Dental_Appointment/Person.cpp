#include "Person.h"

Person::Person(string fName, string mName, string lName, double currentBalance, double maxBalance, string phoneNumber):
name(fName, mName, lName), credit(currentBalance, maxBalance) {
    this->phoneNumber = phoneNumber;
}

void Person::showCustomer() {
    cout << endl;
    name.displayName();
    credit.displayCreditData();
    cout << "Phone number: " << phoneNumber << endl;
}

void Person::showName() {
    name.displayName();
}