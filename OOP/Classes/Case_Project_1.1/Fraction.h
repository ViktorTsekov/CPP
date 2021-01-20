#ifndef FRACTION
#define FRACTION

#include <iostream>

using namespace std;

class Fraction {
    private:
        int wholeNumber;
        int numerator;
        int denominator;

    public:
        const static char separator;

        void enterFractionValue();
        void displayFraction();
        void reduceFraction();
};

#endif