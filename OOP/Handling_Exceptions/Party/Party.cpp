#include "Party.h"

ostream& operator<<(ostream& out, const Party party) {
    out << endl;
    cout << party.meal;
    cout << party.actOfChoise;
    cout << "Number of guests: " << party.numOfGuests << endl;
    cout << "Party cost: " << party.partyCost << endl;

    return out;
}

void Party::setParty() {
    int intInput;
    OutOfRange e(2, 100);

    cout << "Enter meal:\n"; meal.setData();
    cout << "Enter entertainment act:\n"; actOfChoise.setData();
    cout << "Enter number of guests: "; cin >> intInput;

    if(e.theValueIsBad(intInput)) {
        e.setBadNumber(intInput);
        throw(e);
    } else {
        numOfGuests = intInput;
    }

    partyCost = (meal.getPrice() * numOfGuests) + actOfChoise.getFee();
}