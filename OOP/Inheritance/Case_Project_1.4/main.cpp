#include "UserTest.h"

int main() {
    UserTest regularTest;
    UserTest doublingFractionTest;

    regularTest.generateRegularTest();
    doublingFractionTest.generateDoublingFractionTest();

    cout << "\nRegular test:\n";
    regularTest.startSolvingTest();

    cout << "\nDoubling test:\n";
    doublingFractionTest.startSolvingTest();

    return 0;
}