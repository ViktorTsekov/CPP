#ifndef RECTANGLE
#define RECTANGLE

#include <iostream>
#include <string.h>

using namespace std;

class Rectangle {
    protected:
        int length;
        int width;

    public:
        int calculateArea();
        void setRectangleDimensions();
        void displayRectangleDimensions();
};

#endif