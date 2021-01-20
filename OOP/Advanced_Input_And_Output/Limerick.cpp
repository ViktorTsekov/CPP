#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
    const char* fileName = "Limerick.txt";
    string line;
    ofstream fileOutput(fileName);
    ifstream fileInput;

    fileOutput << "Hello" << endl;
    fileOutput << "This is a file" << endl;
    fileOutput << "Bye" << endl;

    fileInput.open(fileName);

    while(getline(fileInput, line)) {
        cout << line << endl;
    }

    return 0;
}