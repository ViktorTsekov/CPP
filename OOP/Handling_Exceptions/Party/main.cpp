#include "Party.h"
#include "OutOfRange.h"

void initialize(Party& party) {
    try {
        party.setParty();
    } catch (const OutOfRange& e) {
        e.showErrorDetails();
        cout << "\nEnter valid data\n\n";
        initialize(party);
    } 
}

int main() {
    Party party;

    initialize(party);
    cout << party;
}