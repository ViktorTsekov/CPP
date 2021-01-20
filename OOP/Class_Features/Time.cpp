#include <iostream>

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

Time::Time(int hours, int minutes) {
    if((hours < 0 || hours > 23) && (minutes < 0 || minutes > 59)) {
        cout << "Error, invalid constructor data" << endl;
        this->hours = 0;
        this->minutes = 0;
    } else if((hours < 0 || hours > 23)) {
        cout << "Error, invalid constructor data" << endl;
        this->hours = 0;
        this->minutes = minutes;
    } else if((minutes < 0 || minutes > 59)) {
        cout << "Error, invalid constructor data" << endl;
        this->hours = hours;
        this->minutes = 0;
    } else {
        this->minutes = minutes;
        this->hours = hours;
    }
}

void Time::addMinutes(int theMinutes) {
    minutes += theMinutes;

    while(minutes >= 60) {
        minutes -= 60;
        hours++;

        if(hours > 23) {
              hours = 0;
        }
    }
}

void Time::displayTime() {
    cout << "Time: ";

    if(hours < 10 && minutes < 10) {
        cout << "0" << hours << ":" << "0" << minutes << endl; 
    } else if(hours < 10) {
        cout << "0" << hours << ":" << minutes << endl; 
    } else if(minutes < 10) {
        cout << hours << ":" << "0" << minutes << endl; 
    } else {
        cout << hours << ":" << minutes << endl; 
    }
}

int main() {
    Time time[5];

    for(int i = 0; i < 5 ; i++) {
        time[i] = Time();
    }

    time[0].addMinutes(120);
    time[3].addMinutes(15);
    time[4].addMinutes(64);

    for(int i = 0; i < 5 ; i++) {
        time[i].displayTime();
    }

}