#ifndef ANTHEM
#define ANTHEM

#include <iostream>
#include <string.h>

#include "MusicalComposition.h"

using namespace std;

class NationalAnthem : public virtual MusicalComposition {
    private:
        string nationality;

    public: 
        NationalAnthem(string title = "", string composer = "", int year = 2000, string nationality = "");
        void displayAnthemData();
};

#endif