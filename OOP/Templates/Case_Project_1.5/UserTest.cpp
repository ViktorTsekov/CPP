#include "UserTest.h"

void UserTest::generateRegularTest() {
    RandomNumbers randomNumbers(1, 15);
    RandomNumbers randomOperations(1, 4);

    numberOfMathProblems = (sizeof(mathProblems) / sizeof(*mathProblems));
    mathProblemInstance.setNumberOfCorrectAnswers(0);
    testType = "regular";

    for(int i = 0; i < numberOfMathProblems; i++) {
        int randomOperation = randomOperations.generateRandomNumber();

        Fraction operandA(randomNumbers.generateRandomNumber(), randomNumbers.generateRandomNumber(), randomNumbers.generateRandomNumber());
        Fraction operandB(randomNumbers.generateRandomNumber(), randomNumbers.generateRandomNumber(), randomNumbers.generateRandomNumber());

        switch (randomOperation)
        {
            case 1: mathProblems[i].setProblem(operandA, operandB, '+'); break;
            case 2: mathProblems[i].setProblem(operandA, operandB, '-'); break;
            case 3: mathProblems[i].setProblem(operandA, operandB, '*'); break;
            case 4: mathProblems[i].setProblem(operandA, operandB, '/'); break;
        }

    }

}

void UserTest::generateDoublingFractionTest() {
    RandomNumbers randomNumbers(1, 15);
    RandomNumbers randomOperations(1, 4);

    numberOfMathProblems = (sizeof(doublingMathProblems) / sizeof(*doublingMathProblems));
    mathProblemInstance.setNumberOfCorrectAnswers(0);
    testType = "doubling";

    for(int i = 0; i < numberOfMathProblems; i++) {
        int randomOperation = randomOperations.generateRandomNumber();

        Fraction operand(randomNumbers.generateRandomNumber(), randomNumbers.generateRandomNumber(), randomNumbers.generateRandomNumber());

        switch (randomOperation)
        {
            case 1: doublingMathProblems[i].setProblem(operand, '+'); break;
            case 2: doublingMathProblems[i].setProblem(operand, '-'); break;
            case 3: doublingMathProblems[i].setProblem(operand, '*'); break;
            case 4: doublingMathProblems[i].setProblem(operand, '/'); break; 
        }

    }

}

void UserTest::startSolvingTest() {
    for(int i = 0; i < numberOfMathProblems; i++) {
        cout << endl;
        if(testType == "regular") {
            mathProblems[i].askUserForAnswer();
        } else if(testType == "doubling") {
            doublingMathProblems[i].askUserForAnswer();
        }
        cout << endl;
    }

    displayEndResult();
}

void UserTest::displayEndResult() {
    int correctAnswers = mathProblemInstance.getNumberOfCorrectAnswers();
    float resultInPercent = (float) correctAnswers / numberOfMathProblems;
    printf("Congratualations you got %d out of %d (%.2f%%)\n", correctAnswers, numberOfMathProblems, resultInPercent * 100);
    mathProblemInstance.setNumberOfCorrectAnswers(0);
}