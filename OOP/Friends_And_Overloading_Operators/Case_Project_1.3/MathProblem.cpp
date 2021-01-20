#include "MathProblem.h"

void MathProblem::setProblem(Fraction operandA, Fraction operandB, char operation) {
    int LCM = findLowestCommonMultiple(operandA.getDenominator(), operandB.getDenominator());
    int answerWholeNumber = operandA.getWholeNumber() + operandB.getWholeNumber();
    int answerNumerator = (LCM / operandA.getDenominator() * operandA.getNumerator()) + (LCM / operandB.getDenominator() * operandB.getNumerator());
    int answerDenominator = LCM;
    Fraction correctAnswer(answerWholeNumber, answerNumerator, answerDenominator);

    this->operandA = operandA;
    this->operandB = operandB;
    this->userAnswer = 0;
    this->correctAnswer = correctAnswer;
    
    if(operation != '+') {
        cout << "Error, unknown operator in constructor: " << operation << endl;
        exit(1);
    } else {
        this->operation = operation;
    }

}

void MathProblem::displayProblem() {
    operandA.displayFraction();
    cout << operation;
    operandB.displayFraction();
    cout << "=?" << endl;
}

void MathProblem::askUserForAnswer() {
    int wholeNumber;
    int numerator;
    int denominator;

    displayProblem();

    cout << "Enter your answer (the fraction must be entered in reduced form)" << endl;
    cout << "Whole part: "; cin >> wholeNumber;
    cout << "Numerator: "; cin >> numerator;
    cout << "Denominator: "; cin >> denominator;

    Fraction userAnswer(wholeNumber, numerator, denominator);
    if(theAnswerIsCorrect(userAnswer)) {
        cout << "Correct!" << endl;
    } else {
        cout << "Incorrect, the correct answer is "; displayCorrectAnswer();
    }
}

void MathProblem::displayCorrectAnswer() {
    cout << correctAnswer.getWholeNumber() << operation << "(" << correctAnswer.getNumerator() << "/" << correctAnswer.getDenominator() << ")" <<endl;
}

bool MathProblem::theAnswerIsCorrect(Fraction fraction) {
    if(correctAnswer.getWholeNumber() == fraction.getWholeNumber() && 
       correctAnswer.getNumerator() == fraction.getNumerator() &&
       correctAnswer.getDenominator() == fraction.getDenominator()) {
    
        return true;
    }

    return false;
}

int MathProblem::findLowestCommonMultiple(int numA, int numB) {
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