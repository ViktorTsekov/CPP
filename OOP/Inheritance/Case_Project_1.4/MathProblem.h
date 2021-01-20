#ifndef MATHPROBLEM
#define MATHPROBLEM

#include <iostream>
#include <string.h>

#include "Fraction.h"

using namespace std;

class MathProblem {
    static int correctAnswers;
    
    protected:
        Fraction operandA;
        Fraction operandB;
        Fraction userAnswer;
        Fraction correctAnswer;
        char operation;

    protected:
        Fraction calculateCorrectAnswer();
        bool theAnswerIsCorrect(Fraction answer);
        
    public:
        int getNumberOfCorrectAnswers();
        void setNumberOfCorrectAnswers(int);
        void setProblem(Fraction operandA, Fraction operandB, char operation);
        void askUserForAnswer();
        void displayProblem();
};

#endif