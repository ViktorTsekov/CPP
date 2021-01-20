#include "MathProblemTemplate.h"
#include "Fraction.h"

int main() {
    Fraction fracA(2, 3, 2);
    Fraction fracB(4, 5, 8);
    MathProblemTemplate<int> integerProblem;
    MathProblemTemplate<double> doubleProblem;
    MathProblemTemplate<Fraction> fractionProblem;
    
    integerProblem.setProblem(5, '+', 4);
    integerProblem.displayProblem();

    doubleProblem.setProblem(5.2, '-', 5.4);
    doubleProblem.displayProblem();

    fractionProblem.setProblem(fracA, '-', fracB);
    fractionProblem.displayProblem();

    return 0;
}