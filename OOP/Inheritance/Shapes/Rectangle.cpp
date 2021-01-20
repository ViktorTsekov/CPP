#include "Rectangle.h"

int Rectangle::calculateArea() {
    return width * length;
}

void Rectangle::setRectangleDimensions() {
    cout << "Set width: "; cin >> width;
    cout << "Set lenght: "; cin >> length;
}

void Rectangle::displayRectangleDimensions() {
    cout << "Width: " << width << endl;
    cout << "Lenght: " << length << endl;
}