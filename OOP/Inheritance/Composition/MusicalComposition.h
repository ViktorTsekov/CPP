#ifndef MUSICALCOMPOSITION
#define MUSICALCOMPOSITION

#include <iostream>
#include <string.h>

using namespace std;

class MusicalComposition {
    private:
        string title;
        string composer;
        int yearWritten;

    public:
        MusicalComposition(string = "", string = "", int = 2000);
        void displayData();
};

#endif