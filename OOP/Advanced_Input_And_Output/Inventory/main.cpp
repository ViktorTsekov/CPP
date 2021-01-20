#include <fstream>

#include "Inventory.h"

int main() {
    const char* fileName = "Data.txt";
    ofstream outFile(fileName);
    ifstream inFile(fileName);
    Inventory inventory[100];
    int n;
    string line;

    cout << "How many inventory items do you want to enter: "; cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Enter record #" << i + 1 << endl;
        cin >> inventory[i];
        cout << endl;
        inventory[i].setProductNumber(i + 1);
        outFile << inventory[i].getLine() << endl;
    }

    cout << "Data:\n";
    while(getline(inFile, line)) {
        cout << line << endl;
    }

}