#ifndef BOOK
#define BOOK

#include <iostream>
#include <string.h>

using namespace std;

class Book {
    private:
        string title;
        string author;

    public:
        void setData();
        void displayData();
};

#endif