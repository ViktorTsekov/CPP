#include "Dog.h"

int main() {
    Dog dogs[4];
    int curDog = 1;

    for(int i = 0; i < 4; i++) {
        cin >> dogs[i];
    }

    cout << endl;

    for(int i = 0; i < 4; i++) {
        cout << "Parent dog " << i + 1 << ": " << endl;
        cout << dogs[i];
    }

    for(int i = 0; i < 4; i++) {
        Dog resultDog;

        for(int j = i + 1; j < 4; j++) {
            resultDog = dogs[i] * dogs[j];
            cout << "Result dog " << curDog << ": " << endl;
            cout << resultDog;
            curDog++;
        }

    }

    return 0;
}