#include "InsurancePolicy.h"

istream& operator>>(istream& in, InsurancePolicy& insurance) {
    cout << endl;
    cout << "Enter policy number: "; in >> insurance.policyNumber;
    cout << "Enter last name: "; in >> insurance.lastName;
    cout << "Enter annual premium: "; in >> insurance.annualPremium;

    return in;
}

string InsurancePolicy::getLine() {
    string line = lastName + " " + to_string(policyNumber) + " " + to_string(annualPremium);
    return line;
}