#include "EntertainmentAct.h"

ostream& operator<<(ostream& out, const EntertainmentAct ea) {
    out << endl;
    out << "Entertainment act details:\n";
    out << "Phone number: " << ea.phoneNumber << endl;
    out << "Fee: " << ea.fee << endl;

    return out;
}

void EntertainmentAct::setData() {
    double doubleInput;
    OutOfRange e(50, 3000);

    cout << "Set phone number: "; cin >> phoneNumber;
    cout << "Set fee: "; cin >> doubleInput;

    if(e.theValueIsBad(doubleInput)) {
        e.setBadNumber(doubleInput);
        throw(e);
    } else {
        fee = doubleInput;
    }

}

double EntertainmentAct::getFee() {
    return fee;
}