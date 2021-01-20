#include "StudentGrade.h"

StudentGrade::StudentGrade(string fName, string mName, string lName, string ID, int testScore, int possiblePoints): 
name(fName, mName, lName) {
    if(testScore < 0) {testScore = 0;}
    if(possiblePoints <= 0) {possiblePoints = 1;}
    if(testScore > possiblePoints) {testScore = possiblePoints;}
    
    this->ID = ID;
    this->testScore = testScore;
    this->possiblePoints = possiblePoints;
}

void StudentGrade::assignGrade() {
    double grade;

    grade = ((double) testScore / (double) possiblePoints) * 100;

    if(grade >= 90) {
        letterGrade = 'A';
    } else if(grade < 90 && grade >= 80) {
        letterGrade = 'B';
    } else if(grade < 80 && grade >= 70) {
        letterGrade = 'D';
    } else if(grade < 70 && grade >= 60) {
        letterGrade = 'C';
    } else if(grade < 60) {
        letterGrade = 'F';
    }

}

void StudentGrade::displayData() {
    cout << endl;
    name.displayName();
    cout << "ID: " << ID << endl;
    cout << "Achieved score: " << testScore << endl;
    cout << "Max score: " << possiblePoints << endl;
    cout << "Grade: " << letterGrade << endl;
}