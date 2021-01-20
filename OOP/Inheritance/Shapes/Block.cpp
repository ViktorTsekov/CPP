#include "Rectangle.h"
#include "Block.h"

int Block::calculateArea() {
    return height * width * length;
}

void Block::setBlockDimensions() {
    setRectangleDimensions();
    cout << "Set height: "; cin >> height;
    cout << endl;
}

void Block::displayBlockDimensions() {
    displayRectangleDimensions();
    cout << "Height: " << height << endl;
    cout << endl;
}