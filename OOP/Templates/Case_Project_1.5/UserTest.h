#ifndef USERTEST
#define USERTEST

#include <iostream>
#include <string.h>
#include <cstdio>

#include "RandomNumbers.h"
#include "MathProblem.h"
#include "DoublingMathProblem.h"
#include "Fraction.h"

class UserTest {
    private:
        int numberOfMathProblems;
        string testType;
        MathProblem mathProblemInstance;
        MathProblem mathProblems[5];
        DoublingMathProblem doublingMathProblems[5];

    public:
        void generateRegularTest();
        void generateDoublingFractionTest();
        void startSolvingTest();
        void displayEndResult();
};

#endif