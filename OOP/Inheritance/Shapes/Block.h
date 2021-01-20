#ifndef BLOCK
#define BLOCK

#include <iostream>
#include <string.h>

#include "Rectangle.h"

using namespace std;

class Block: virtual public Rectangle {
    protected:
        int height;
    
    public: 
        int calculateArea();
        void setBlockDimensions();
        void displayBlockDimensions();
};

#endif