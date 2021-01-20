#include "Rectangle.h"
#include "Block.h"

int main() {
    Rectangle rectangle;
    Block block;

    cout << "Rectangle: " << endl;
    rectangle.setRectangleDimensions();
    cout << endl << "Area: " << rectangle.calculateArea() << endl << endl;

    cout << "Block: " << endl;
    block.setBlockDimensions();
    cout << "Area: " << block.calculateArea() << endl;
}