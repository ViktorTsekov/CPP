#include<iostream>
#include<iomanip>

using namespace std;

ostream& gpa(ostream& s) {
    s << setprecision(3);
    s << fixed;
    s.width(7);
    return s;
}

int main() {
    const int NUM = 10;
    double gradePoints[NUM];
    int x;

    for(x = 0; x < NUM; ++x) {
        cout << "Enter grade point average for student " <<
        (x + 1) << " ";
        cin >> gradePoints[x];
    }

    cout << endl << "Grade point averages are " << endl;
    for(x = 0; x < NUM; ++x)
         cout << gpa << gradePoints[x] << endl;
         
    return 0;
}