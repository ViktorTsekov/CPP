#include "Exception.h"

void Exception::setErrorMessage(string msg) {
    messageError = msg;
}

bool Exception::checkIfValueIsOutOfRange(double val, double bottomBoundary, double upperBoundary, Exception& e) {
    if(val < bottomBoundary || val > upperBoundary) {
        string msg = "Argument " + to_string(val) + " caused out of range error. Value needs to be between " + to_string(bottomBoundary) + " and " + to_string(upperBoundary);
        e.setErrorMessage(msg);
        return true;
    }

    return false;
}

bool Exception::checkIfValueIsOutOfRange(string arg, int minLenght, int maxLenght, Exception& e) {
    if(arg.length() < minLenght || arg.length() > maxLenght) {
        string msg = "Argument " + arg + " caused lenght error. Lenght needs to be between " + to_string(minLenght) + " and " + to_string(maxLenght);
        e.setErrorMessage(msg);
        return true;
    }

    return false;
}

bool Exception::checkIfValueIsMismatched(double val, Exception& e) {
    if(!(val)) {
        string msg = "Invalid argument, type needs to be double";
        e.setErrorMessage(msg);
        return true;
    }

    return false;
}

void Exception::getErrorDetails() {
    cout << messageError << endl;
}