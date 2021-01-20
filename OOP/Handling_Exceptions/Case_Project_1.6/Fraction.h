#ifndef FRACTION
#define FRACTION

#include <iostream>

using namespace std;

class Fraction {
    friend istream& operator>>(istream&, Fraction&);
    friend ostream& operator<<(ostream&, const Fraction&);

    protected:
        int wholeNumber;
        int numerator;
        int denominator;

    public:
        const static char separator;

        Fraction(int wholeNumber = 0, int numerator = 0, int denominator = 1);
        bool operator==(Fraction);
        bool operator<(double);
        Fraction operator+(Fraction);
        Fraction operator-(Fraction);
        Fraction operator*(Fraction);
        Fraction operator/(Fraction);
        int getWholeNumber();
        int getNumerator();
        int getDenominator();
        int findLowestCommonMultiple(int, int); 
        void displayFraction(char = '*');
        void displayEquation(Fraction, Fraction, Fraction, char);
        void reduceFraction();
};

#endif