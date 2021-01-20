#include "FractionException.h"

int main() {
    
    try {
        FractionException frExcp(3, 2, 4);
        cout << "Fraction: " << frExcp << endl;
    } catch(Exception& e) {
        e.getErrorDetails();
        exit(1);
    }
    
    return 0;
}