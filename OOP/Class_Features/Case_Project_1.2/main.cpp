#include "Fraction.h"
#include "MathProblem.h"

int main() {
    Fraction Fraction1(2, 2, 3);
    Fraction Fraction2(2, 4, 3);
    Fraction Fraction3(8, 8, 5);
    Fraction Fraction4(2, 4, 10);
    Fraction Fraction5(41, 24, 12);
    Fraction Fraction6(58, 7, 3);
    MathProblem mathProblems[3];

    mathProblems[0].setProblem(Fraction1, Fraction2, '+');
    mathProblems[1].setProblem(Fraction3, Fraction4, '+');
    mathProblems[2].setProblem(Fraction5, Fraction6, '+');

    for(int i = 0; i < 3; i++) {
        cout << endl;
        mathProblems[i].askUserForAnswer();
    }

    return 0;
}