#ifndef CREDITDATA
#define CREDITDATA

#include <iostream>
#include <string>

using namespace std;

class CreditData
{
    private:
        double currentBalance;
        double maxBalance;

    public:
        CreditData(double = 0, double = 0);
        void displayCreditData();
};

#endif