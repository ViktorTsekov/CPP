#ifndef TIME
#define TIME

#include <iostream>
#include <string.h>

using namespace std;

class Time {
    private:
        int hours;
        int minutes;

    public:
        Time(int = 0, int = 0);
        void addMinutes(int theMinutes);
        void displayTime();
};

#endif