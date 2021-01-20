#ifndef INPUT
#define INPUT

#include <iostream>
#include <string.h>

using namespace std;

class StandardInput {
    public:
        template <class T>
            void inputClass(T&, int);
};

template <class T>
void StandardInput::inputClass(T& theClass, int numOfArgs) {
    cout << "You are about to enter " << numOfArgs << " arguments\n\n";

    for(int i = 0; i < numOfArgs; i++) {
        cout << "Arg " << i + 1 << ":\n";
        cin >> theClass;
    }
}


#endif