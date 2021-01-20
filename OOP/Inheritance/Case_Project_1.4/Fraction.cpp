#include "Fraction.h"

const char Fraction::separator = '/';

istream& operator>>(istream& in, Fraction& frac) {
    cout << endl;
    cout<<"Enter whole part: "; in>>frac.wholeNumber;
    cout<<"Enter numerator: "; in>>frac.numerator;
    cout<<"Enter denominator: "; in>>frac.denominator;

    if(frac.denominator == 0) {
        cout<<"Denominator can not be 0\n";
        exit(1);
    }

    cout << endl;
    return in;
}

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

Fraction Fraction::operator+(Fraction frac) {
    int LCM = findLowestCommonMultiple(denominator, frac.getDenominator());
    int resultWholeNumber = wholeNumber + frac.getWholeNumber();
    int resultNumerator = (LCM / denominator * numerator) + (LCM / frac.getDenominator() * frac.getNumerator());
    int resultDenominator = LCM;
    Fraction tempFraction(resultWholeNumber, resultNumerator, resultDenominator);

    return tempFraction;
}

Fraction Fraction::operator-(Fraction frac) {
    int LCM = findLowestCommonMultiple(denominator, frac.getDenominator());
    int resultWholeNumber = wholeNumber - frac.getWholeNumber();
    int resultNumerator = (LCM / denominator * numerator) - (LCM / frac.getDenominator() * frac.getNumerator());
    int resultDenominator = LCM;
    Fraction tempFraction(resultWholeNumber, resultNumerator, resultDenominator);

    return tempFraction;
}

Fraction Fraction::operator*(Fraction frac) {
    int tempNumeratorA = wholeNumber * denominator + numerator;
    int tempNumeratorB = frac.wholeNumber * frac.denominator + frac.numerator;
    int resultNumerator = tempNumeratorA * tempNumeratorB;
    int resultDenominator = denominator * frac.denominator;
    Fraction tempFraction(0, resultNumerator, resultDenominator);

    return tempFraction;
}

Fraction Fraction::operator/(Fraction frac) {
    int tempNumeratorA = wholeNumber * denominator + numerator;
    int tempNumeratorB = frac.wholeNumber * frac.denominator + frac.numerator;
    int resultNumerator = tempNumeratorA * frac.denominator;
    int resultDenominator = tempNumeratorB * denominator;
    Fraction tempFraction(0, resultNumerator, resultDenominator);

    return tempFraction;
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

int Fraction::findLowestCommonMultiple(int numA, int numB) {
    int max = (numA > numB) ? numA : numB;

    do
    {
        if (max % numA == 0 && max % numB == 0) {
            break;
        } else {
            ++max;
        }
    } while (true);

    return max;
}

void Fraction::displayFraction(char operation) {
    cout << wholeNumber << operation << "(" << numerator << separator << denominator << ")";
}

void Fraction::displayEquation(Fraction operandA, Fraction operandB, Fraction result, char operation) {
    operandA.displayFraction();
    cout << operation;
    operandB.displayFraction();
    cout << "=";
    result.displayFraction('+');
    cout << endl;
}

void Fraction::reduceFraction() {
    for (int i = denominator * numerator; i > 1; i--) {  
        if ((denominator % i == 0) && (numerator % i == 0)) {  
            denominator /= i;  
            numerator /= i;  
        }  
    }
}