#ifndef NAME
#define NAME

#include <iostream>
#include <string.h>

using namespace std;

class Name {
    private:
        string firstName;
        string middleName;
        string lastName;

    public:
        Name(string fName = "", string mName = "", string lName = "");
        void displayName();
};

#endif