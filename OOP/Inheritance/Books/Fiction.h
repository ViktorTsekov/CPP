#ifndef FICTION
#define FICTION

#include <iostream>
#include <string.h>

#include "Book.h"

using namespace std;

class Fiction : public virtual Book {
    private:
        int gradeLevel;

    public:
        void setFictionData();
        void displayFictionData();
};

#endif