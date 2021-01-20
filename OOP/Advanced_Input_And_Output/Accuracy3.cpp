#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float numbers[5];

    for(int i = 0; i < 5; i++) {
        cout << "Enter number #" << i + 1 << ": "; cin >> numbers[i];
    }

    cout.precision(3);
    for(int i = 0; i < 5; i++) {
        cout << "Number #" << i + 1 << ": " << numbers[i] << endl;
    }

}