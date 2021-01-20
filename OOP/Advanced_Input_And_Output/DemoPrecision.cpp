#include<iostream>
#include<iomanip>

using namespace std;

int main() {
    int x;
    const int FIELD_SIZE = 10;
    const int ARRAY_SIZE = 5;
    double values[ARRAY_SIZE];

    values[0] = 23.4;
    for(x = 0; x < (ARRAY_SIZE - 1); ++x)
        values[x+1] = values[x] * 0.10;

    for(x = 0; x < ARRAY_SIZE; ++x) {
        cout.width(FIELD_SIZE);
        cout << values[x] << endl;
    }

    cout.precision(2);
    cout << "After precision(2) call" << endl;
    for(x = 0; x < ARRAY_SIZE; ++x) {
        cout.width(FIELD_SIZE);
        cout << values[x] << endl;
    }

    cout << fixed;
    cout << "After fixed is added" << endl;
    for(x = 0; x < ARRAY_SIZE; ++x) {
        cout.width(FIELD_SIZE);
        cout << values[x] << endl;
    }

    return 0;
}