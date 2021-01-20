#ifndef COLLEGECOURSE
#define COLLEGECOURSE

#include <iostream>
#include <string.h>

using namespace std;

class CollegeCourse {
    friend istream& operator>>(istream&, CollegeCourse&);

    private:
        int creditsEarned;
        string courseID;
        char grade;

    public:
        CollegeCourse(int = 0, string = "", char = '-');
};

#endif