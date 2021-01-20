#include "Fraction.h"
#include "MathProblem.h"

int main() {
    Fraction fractionA;
    Fraction fractionB;
    Fraction result;
    char operation;

    cout << "Operand A:"; cin >> fractionA;
    cout << "Operand B:"; cin >> fractionB;
    cout << "Operation(+,-,*,/): "; cin >> operation;

    switch (operation)
    {
        case '+': result =  fractionA + fractionB; break;
        case '-': result =  fractionA - fractionB; break;
        case '*': result =  fractionA * fractionB; break;
        case '/': result =  fractionA / fractionB; break;
        default: cout << "Invalid operation!" << endl; break;
    }

    return 0;
}