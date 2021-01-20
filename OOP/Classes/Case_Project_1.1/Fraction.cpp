#include "Fraction.h"

const char Fraction::separator = '/';

void Fraction::enterFractionValue() {
    cout<<"Enter whole part: "; cin>>wholeNumber;
    cout<<"Enter numerator: "; cin>>numerator;
    cout<<"Enter denominator: "; cin>>denominator;

    if(denominator == 0) {
        cout<<"Denominator can not be 0\n";
        cout<<"Try again!\n\n";
        enterFractionValue();
    }

}

void Fraction::displayFraction() {
    cout<<"Result: " <<wholeNumber <<"*(" <<numerator <<separator <<denominator <<")" <<endl;
}

void Fraction::reduceFraction() {
    for (int i = denominator * numerator; i > 1; i--) {  
        if ((denominator % i == 0) && (numerator % i == 0)) {  
            denominator /= i;  
            numerator /= i;  
        }  
    }
}