#include "StandardInput.h"
#include "CollegeCourse.h"

int main() {
    CollegeCourse course;
    StandardInput input;
    int arg;

    input.inputClass(course, 3);
    cout << "\nEnter integer:\n"; input.inputClass(arg, 1);

    cout << "Integer: " << arg << endl;
}