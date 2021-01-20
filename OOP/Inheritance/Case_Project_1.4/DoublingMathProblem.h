#ifndef DOUBLINGMATHPROBLEM
#define DOUBLINGMATHPROBLEM

#include <iostream>
#include <string.h>

#include "MathProblem.h"

class DoublingMathProblem : public virtual MathProblem {
    public:
        void setProblem(Fraction operand, char operation);
};

#endif