#include <iostream>
#include <string>

using namespace std;

class Date {
    private:
        int day;
        int month;
        int year;

    public:
        Date(int = 1, int = 1, int = 2000);
        void displayDate();
};

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

void Date::displayDate() {
    cout << day << "/" << month << "/" << year << endl;
}

int main() {
    Date date1;
    Date date2(17, 8, 2000);

    date1.displayDate();
    date2.displayDate();
}