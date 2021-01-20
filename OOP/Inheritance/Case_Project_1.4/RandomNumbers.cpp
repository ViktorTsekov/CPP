#include "RandomNumbers.h"

RandomNumbers::RandomNumbers(int min, int max) {
    bottomBoundary = min;
    upperBoundary = max;
    generateRandomSeed();
}

void RandomNumbers::generateRandomSeed() {
    srand((unsigned)time(NULL));

    for(int i = 0; i < 1000; i++) {
        randomSeed[i] = rand() % (upperBoundary - bottomBoundary + 1) + bottomBoundary;
    }
}

int RandomNumbers::generateRandomNumber() {
    int i = rand() % 1000 + 0;
    return randomSeed[i];
}