#include "MathProblem.h"

int MathProblem::correctAnswers = 0;

int MathProblem::getNumberOfCorrectAnswers() {
    return correctAnswers;
}

void MathProblem::setNumberOfCorrectAnswers(int arg) {
    correctAnswer = arg;
}

Fraction MathProblem::calculateCorrectAnswer() {
    Fraction result;

    switch (operation)
    {
        case '+': result =  operandA + operandB; break;
        case '-': result =  operandA - operandB; break;
        case '*': result =  operandA * operandB; break;
        case '/': result =  operandA / operandB; break;
        default: cout << "Invalid operation: " << operation << endl; exit(1); break;
    }

    return result;
}

void MathProblem::setProblem(Fraction operandA, Fraction operandB, char operation) {
    this->operandA = operandA;
    this->operandB = operandB;
    this->userAnswer = 0;
    this->operation = operation;
    this->correctAnswer = calculateCorrectAnswer();
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
        correctAnswers++;
    } else {
        cout << "Incorrect, the correct answer is "; correctAnswer.displayFraction('+');
        cout << endl;
    }
}

bool MathProblem::theAnswerIsCorrect(Fraction fraction) {
    if(correctAnswer.getWholeNumber() == fraction.getWholeNumber() && 
       correctAnswer.getNumerator() == fraction.getNumerator() &&
       correctAnswer.getDenominator() == fraction.getDenominator()) {
        return true;
    }

    return false;
}