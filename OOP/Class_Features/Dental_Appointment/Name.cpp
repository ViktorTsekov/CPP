#include "Name.h"

Name::Name(string fName, string mName, string lName) {
    firstName = fName;
    middleName = mName;
    lastName = lName;
}

void Name::displayName() {
    cout << firstName << " " << middleName << " " << lastName << endl; 
}