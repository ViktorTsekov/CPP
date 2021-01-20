#include "FractionException.h"

FractionException::FractionException(int whole, int num, int den) {
    Exception e;

    if(e.checkIfValueIsOutOfRange(whole, 0, 20, e)) {
        throw(e);
    } else{
        wholeNumber = whole;
    }

    if(e.checkIfValueIsOutOfRange(num, 0, 20, e)) {
        throw(e);
    } else {
        numerator = num;
    }

    if(e.checkIfValueIsOutOfRange(den, 1, 20, e)) {
        throw(e);
    } else {
        denominator = den;
    }

    this->reduceFraction();
}