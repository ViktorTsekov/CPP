#ifndef MATHPROBLEM
#define MATHPROBLEM

#include <iostream>
#include <string.h>

#include "Fraction.h"

using namespace std;

class MathProblem {
    private:
        Fraction operandA;
        Fraction operandB;
        Fraction userAnswer;
        Fraction correctAnswer;
        char operation;
        
    public: 
        int findLowestCommonMultiple(int numA, int numB);
        bool theAnswerIsCorrect(Fraction answer);
        void setProblem(Fraction operandA, Fraction operandB, char operation);
        void askUserForAnswer();
        void displayProblem();
        void displayCorrectAnswer();
};

#endif