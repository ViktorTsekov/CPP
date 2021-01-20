#include "CollegeCourse.h"

istream& operator>>(istream& in, CollegeCourse& course) {
    static int argIndex = 1;

    switch (argIndex) {
        case 1: cout << "Credits: "; in >> course.creditsEarned; break;
        case 2: cout << "ID: "; in >> course.courseID; break;
        case 3: cout << "Grade: "; in >> course.grade; break;
        default: cout << "Out of scope!\n"; exit(1); break;
    }

    argIndex++;
    return in;
}

CollegeCourse::CollegeCourse(int creditsEarned, string courseID, char grade) {
    this->creditsEarned = creditsEarned;
    this->courseID = courseID;
    this->grade = grade;
}