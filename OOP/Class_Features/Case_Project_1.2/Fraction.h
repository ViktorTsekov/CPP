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

        Fraction(int wholeNumber = 0, int numerator = 0, int denominator = 1);
        int getWholeNumber();
        int getNumerator();
        int getDenominator();
        void enterFractionValue();
        void displayFraction();
        void reduceFraction();
};

#endif