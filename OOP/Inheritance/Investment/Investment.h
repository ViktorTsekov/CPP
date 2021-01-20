#ifndef INVESTMENT
#define INVESTMENT

#include <iostream>
#include <string.h>

using namespace std;

class Investment {
    private:
        double initialValue;
        double currentValue;
        double profit;
        double percentProfit;

    public:
        Investment(double = 0, double = 0);
        void displayInvestment();
};

#endif