#include <iostream>

using namespace std;

int power(int x, int n) {
    static int result = 1;

    if(n > 0) {
        result *= x;
        power(x, n - 1);
    }

    return result;
}

int main() {
    cout << power(2, 4) << endl;
}