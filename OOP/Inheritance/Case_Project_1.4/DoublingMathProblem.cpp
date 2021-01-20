#include "DoublingMathProblem.h"

void DoublingMathProblem::setProblem(Fraction operand, char operation) {
    this->operandA = operand;
    this->operandB = operand;
    this->userAnswer = 0;
    this->operation = operation;
    this->correctAnswer = calculateCorrectAnswer();
}