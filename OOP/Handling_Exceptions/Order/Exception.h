#ifndef EXCEPTION
#define EXCEPTION

#include <iostream>
#include <string.h>

using namespace std;

class Exception {
    private:
        string messageError;

    public:
        void setErrorMessage(string);
        bool checkIfValueIsOutOfRange(double, double, double, Exception&);
        bool checkIfValueIsOutOfRange(string, int, int, Exception&);
        bool checkIfValueIsMismatched(double, Exception&);
        void getErrorDetails();
};

#endif