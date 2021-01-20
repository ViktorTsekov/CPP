#ifndef INSURANCE
#define INSURANCE

#include <iostream>
#include <string.h>

using namespace std;

class InsurancePolicy {
    friend istream& operator>>(istream&, InsurancePolicy&);

    private:
        int policyNumber;
        string lastName;
        int annualPremium;

    public:
        string getLine();
};

#endif