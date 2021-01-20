#include <iostream>
#include <string.h>

using namespace std;

class GraduationCandidate {
    private:
        string ID;
        string firstName;
        string lastName;
        unsigned hasCompletedCreditHours:1;
        unsigned hasCompletedMajor:1;
        unsigned hasPaidCampusFees:1;
        unsigned hasPaidLibraryFees:1;
        unsigned hasPaidGraduationFees:1;

    public:
        GraduationCandidate(string, string, string, int, int, int, int, int);
        int convertBits();
};

GraduationCandidate::GraduationCandidate(string ID, string fName, string lName, int bit1, int bit2, int bit3, int bit4, int bit5) {
    this->ID = ID;
    firstName = fName;
    lastName = lName;
    hasCompletedCreditHours = bit1;
    hasCompletedMajor = bit2;
    hasPaidCampusFees = bit3;
    hasPaidLibraryFees = bit4;
    hasPaidGraduationFees = bit5;
}

int GraduationCandidate::convertBits() {
    int temp = hasCompletedCreditHours * 2 + 
               hasCompletedMajor * 4 +
               hasPaidCampusFees * 8 +
               hasPaidLibraryFees * 16 +
               hasPaidGraduationFees * 32;

    return temp;
}

int main() {
    //Code 62 means that a student can graduate
    GraduationCandidate candidate("28001040", "Viktor", "Tsekov", 1, 0, 1, 0, 1);
    
    if(candidate.convertBits() == 62) {
        cout << "Student can graduate" << endl;
    } else {
        cout << "Student is unable to graduate" << endl;
    }
}