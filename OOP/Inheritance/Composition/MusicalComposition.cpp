#include "MusicalComposition.h"

MusicalComposition::MusicalComposition(string title, string composer, int year) {
    this->title = title;
    this->composer = composer;
    this->yearWritten = year;
}

void MusicalComposition::displayData() {
    cout << "Title: " << title << endl;
    cout << "Composer: " << composer << endl;
    cout << "Year written: " << yearWritten << endl;
}