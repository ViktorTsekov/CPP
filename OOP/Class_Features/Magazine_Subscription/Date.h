#ifndef DATE
#define DATE

#include <iostream>
#include <string.h>

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

#endif