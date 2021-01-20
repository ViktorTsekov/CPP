#ifndef FRACTIONEXCEPTION
#define FRACTIONEXCEPTION

#include <iostream>
#include <string.h>

#include "Fraction.h"
#include "Exception.h"

using namespace std;

class FractionException : virtual public Fraction {
    public:
        FractionException(int, int, int);
};

#endif