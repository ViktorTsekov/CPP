#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

int main() {
    string name;
    int count;
    const char* FILENAME = "MyFriends.txt";
    ofstream writingFile(FILENAME);
    ifstream readingFile;

    if(!writingFile.good())
        cout << "File could not be opened for writing" <<
        endl;
    else {
        cout << "Enter a name or end-of-file to quit ";
        while(cin >> name) {
            writingFile << name << endl;
            cout << "Enter a name or end-of-file to quit ";
        }
    }

    writingFile.close();
    readingFile.open(FILENAME);
    count = 0;

    if(!readingFile.good())
        cout << "File could not be opened for reading" <<
        endl;
    else {
        while(readingFile >> name) {
            ++count;
            cout << "Friend #" << count << " " <<
            name << endl;
        }
        cout << endl << "Total number of friends is " <<
        count << endl;
    }

    return 0;
}