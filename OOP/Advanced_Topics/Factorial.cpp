#include <iostream>

using namespace std;

int factorial(int n) {
    static int result = 1;

    if(n > 1) {
        result *= n;
        factorial(n - 1);
    }

    return result;
}

int main() {
    cout << factorial(4) << endl;
}