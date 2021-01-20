#ifndef RANDOMNUMBERS
#define RANDOMNUMBERS

#include <iostream>
#include <string.h>

using namespace std;

class RandomNumbers {
    private:
        int randomSeed[1000];
        int bottomBoundary;
        int upperBoundary;

    protected:
        void generateRandomSeed();

    public: 
        RandomNumbers(int = 0, int = 1);
        int generateRandomNumber();
};

#endif