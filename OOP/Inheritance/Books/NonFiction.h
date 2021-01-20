#ifndef NONFICTION
#define NONFICTION

#include <iostream>
#include <string.h>

#include "Book.h"

using namespace std;

class NonFiction : public virtual Book {
    private:
        int numberOfPages;

    public:
        void setNonFictionData();
        void displayNonFictionData();
};

#endif