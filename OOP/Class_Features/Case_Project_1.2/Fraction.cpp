#include "Fraction.h"

const char Fraction::separator = '/';

Fraction::Fraction(int wholeNumber, int numerator, int denominator) {
    this->wholeNumber = wholeNumber;
    this->numerator = numerator;

    if(denominator == 0) {
        cout<<"Denominator can not be 0\n";
        denominator = 1;
    } else {
        this->denominator = denominator;
    }
    
    reduceFraction();
}

int Fraction::getWholeNumber() {
    return wholeNumber;
}

int Fraction::getNumerator() {
    return numerator;
}

int Fraction::getDenominator() {
    return denominator;
}

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
    cout<<wholeNumber <<"*(" <<numerator <<separator <<denominator <<")";
}

void Fraction::reduceFraction() {
    for (int i = denominator * numerator; i > 1; i--) {  
        if ((denominator % i == 0) && (numerator % i == 0)) {  
            denominator /= i;  
            numerator /= i;  
        }  
    }
}