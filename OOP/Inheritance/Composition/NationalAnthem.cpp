#include "NationalAnthem.h"

NationalAnthem::NationalAnthem(string title, string composer, int year, string nationality):
    MusicalComposition(title, composer, year) {
    this->nationality = nationality;
}

void NationalAnthem::displayAnthemData() {
    displayData();
    cout << "Nationality of anthem: " << nationality << endl;
}