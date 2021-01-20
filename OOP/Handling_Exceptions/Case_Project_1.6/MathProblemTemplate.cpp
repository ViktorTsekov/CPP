#include "MathProblemTemplate.h"

template <class T>
bool MathProblemTemplate<T>::theAnswerIsCorrect() {
    T temp = userAnswer - correctAnswer;
    const double epsilon = 0.00001;
    return (temp < epsilon);
}

template <class T>
void MathProblemTemplate<T>::setProblem(T argA, char operation, T argB) {
    this->operandA = argA;
    this->operation = operation;
    this->operandB = argB;
    this->userAnswer = 0;

    switch (operation)
    {
        case '+': correctAnswer = operandA + operandB; break;
        case '-': correctAnswer = operandA - operandB; break;
        case '/': correctAnswer = operandA / operandB; break;
        case '*': correctAnswer = operandA * operandB; break;
        default: cout << "Invalid operator!\n"; exit(1); break;
    }

}

template <class T>
void MathProblemTemplate<T>::displayProblem() {
    cout << operandA << operation << operandB << "=?";
    promptUserForAnswer();
}

template <class T>
void MathProblemTemplate<T>::promptUserForAnswer() {
    cout << "\nEnter your answer:\n";
    cin >> userAnswer;

    if(theAnswerIsCorrect()) cout << "Correct!" << endl << endl;
    else cout << "Incorrect, the correct answer is " << correctAnswer << endl << endl;
}

template class MathProblemTemplate<int>;
template class MathProblemTemplate<double>;
template class MathProblemTemplate<Fraction>;