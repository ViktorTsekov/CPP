#include "OutOfRange.h"

OutOfRange::OutOfRange(double min, double max):
out_of_range("Out of range!") {
    bottomBoundary = min;
    upperBoundary = max;
}

void OutOfRange::setBadNumber(double val) {
    badNumber = val;
}

bool OutOfRange::theValueIsBad(double val) {
    return (val < bottomBoundary || val > upperBoundary);
}

void OutOfRange::showErrorDetails() const {
    cout << badNumber << " was out of range, the value needs to be between " << bottomBoundary << " and " << upperBoundary;
}