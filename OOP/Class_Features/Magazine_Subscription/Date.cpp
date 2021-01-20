#include "Date.h"

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

void Date::displayDate() {
    if(day <= 9) {
        cout << "0" << day << "/" << month << "/" << year << endl;
    } else if(month <= 9) {
        cout << day << "/" << "0" << month << "/" << year << endl;
    } else if(day <= 9 && month <= 9) {
        cout << "0" << day << "/" << "0" << month << "/" << year << endl;
    } else {
        cout << day << "/" << month << "/" << year << endl;
    }
}