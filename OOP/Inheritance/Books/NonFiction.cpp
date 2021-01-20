#include "NonFiction.h"

void NonFiction::setNonFictionData() {
    setData();
    cout << "Set number of pages: "; cin >> numberOfPages;
}

void NonFiction::displayNonFictionData() {
    displayData();
    cout << "Number of pages: " << numberOfPages << endl;
}