#include "Average.h"
#include "CollegeCourse.h"

int main() {
    CollegeCourse courseA(23, "Math", 'A');
    CollegeCourse courseB(21, "Engl", 'A');
    Average calc;

    cout << courseA;
    cout << courseB;
    cout << "Average: " << calc.calcAverage(courseA, courseB) << endl;
}