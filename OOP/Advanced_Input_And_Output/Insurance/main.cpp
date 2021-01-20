#include <fstream>

#include "InsurancePolicy.h"

int main() {
    const char* fileName = "Data.txt";
    string line;
    InsurancePolicy policies[5];
    ofstream outFile(fileName);
    ifstream inFile;

    cout << "Enter Data:\n";

    for(int i = 0; i < 5; i++) {
        cin >> policies[i];
    }

    for(int i = 0; i < 5; i++) {
        outFile << policies[i].getLine() << endl;
    }

    outFile.close();
    inFile.open(fileName);

    cout << "\nData:\n";
    while(getline(inFile, line)) {
        cout << line << endl;
    }

}