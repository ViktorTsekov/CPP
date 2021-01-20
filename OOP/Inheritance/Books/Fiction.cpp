#include "Fiction.h"

void Fiction::setFictionData() {
    setData();
    cout << "Set grade: "; cin >> gradeLevel;
}

void Fiction::displayFictionData() {
    displayData();
    cout << "Grade: " << gradeLevel << endl;
}