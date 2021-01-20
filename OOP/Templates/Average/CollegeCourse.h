#ifndef COLLEGECOURSE
#define COLLEGECOURSE

#include <iostream>
#include <string.h>

using namespace std;

class CollegeCourse {
    friend ostream& operator<<(ostream&, const CollegeCourse&);

    private:
        int creditsEarned;
        int honoursPoints;
        string courseID;
        char grade;

    public:
        CollegeCourse(int = 0, string = "", char = '-');
        CollegeCourse operator+(CollegeCourse);
        double operator/(int);
};

#endif