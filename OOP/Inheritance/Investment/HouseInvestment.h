#ifndef HOUSEINVESTMENT
#define HOUSEINVESTMENT

#include <iostream>
#include <string.h>

#include "House.h"
#include "Investment.h"

using namespace std;

class HouseInvestment : House, Investment {
    public:
        HouseInvestment(double = 0, double = 0, string = "", int = 0);
        void displayHouseInvestment();
};

#endif