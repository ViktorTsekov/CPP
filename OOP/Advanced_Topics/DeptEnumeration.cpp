#include <iostream>

using namespace std;

int main() {
    enum Depts {ACCT, BUS, CIS, MGMT, MRKTG};
    int x;
    double credits;
    double total = 0;

    for(x = ACCT; x <= MRKTG; ++x) {
        cout << "Enter credit hours earned in department " <<
        (x + 1) << " >> ";
        cin >> credits;
        total += credits;
    }

    cout << "Total credits earned is " << total << endl;
}