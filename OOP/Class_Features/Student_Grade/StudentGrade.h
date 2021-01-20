#ifndef STUDENTGRADE
#define STUDENTGRADE

#include <iostream>
#include <string.h>

#include "Name.h"

using namespace std;

class StudentGrade {
    private:
        Name name;
        string ID;
        int testScore;
        int possiblePoints;
        char letterGrade;

    public:
        StudentGrade(string fName = "", string mName = "", string lName = "", string ID = "", int testScore = 0, int possiblePoints = 100); 
        void assignGrade();
        void displayData();
};

#endif