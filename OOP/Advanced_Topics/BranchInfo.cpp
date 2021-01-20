#include <iostream>
#include <string.h>

using namespace std;


void branchInfo() {
    enum Branches {NORTH , SOUTH , EAST , WEST , CENTRAL};

    for(int i = NORTH; i <= CENTRAL; i++) {
        switch (i)
        {
            case 0: cout << "North" << endl; break;
            case 1: cout << "South" << endl; break;
            case 2: cout << "East" << endl; break;
            case 3: cout << "West" << endl; break;
            case 4: cout << "Central" << endl; break;
        }
    }
}

int main() {
    branchInfo();
}