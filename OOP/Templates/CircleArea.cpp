#include <iostream>

using namespace std;

class CircleArea {
    public:
        template <class T>
            T calculateArea(T rad = 0);
};

template <class T>
T CircleArea::calculateArea(T rad) {
    return 3.14 * rad * rad;
}

int main() {
    CircleArea area;
    int arg = 2;

    cout << "Circle area: " << area.calculateArea<double>(arg) << endl;
}