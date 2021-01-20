#ifndef MATHPROBLEM
#define MATHPROBLEM

#include <iostream>
#include <string.h>
#include <cstdlib>

#include "Fraction.h"

using namespace std;

template <class T>
class MathProblemTemplate {
    private:
        T operandA;
        T operandB;
        T userAnswer;
        T correctAnswer;
        char operation;
        
    public:
        bool theAnswerIsCorrect();
        void setProblem(T, char, T);
        void displayProblem();
        void promptUserForAnswer();
};

#endif