#include "CollegeCourse.h"

ostream& operator<<(ostream& out, const CollegeCourse& course) {
    out << endl;
    out << "Course ID: " << course.courseID << endl;
    out << "Credits: " << course.creditsEarned << endl;
    out << "Grade: " << course.grade << endl;
    out << "Honour points: " << course.honoursPoints << endl;
    out << "**********************" << endl;

    return out;
}

CollegeCourse::CollegeCourse(int creditsEarned, string courseID, char grade) {
    this->creditsEarned = creditsEarned;
    this->courseID = courseID;
    this->grade = grade;

    switch (grade)
    {
        case 'A': honoursPoints = creditsEarned + 4; break;
        case 'B': honoursPoints = creditsEarned + 3; break;
        case 'C': honoursPoints = creditsEarned + 2; break;
        case 'D': honoursPoints = creditsEarned + 1; break;
    }

}

CollegeCourse CollegeCourse::operator+(CollegeCourse course) {
    CollegeCourse temp;
    temp.courseID = "Honour points summary";
    temp.honoursPoints = this->honoursPoints + course.honoursPoints;
    return temp;
}

double CollegeCourse::operator/(int arg) {
    return this->honoursPoints / arg;
}