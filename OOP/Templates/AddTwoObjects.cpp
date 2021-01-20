#include <iostream>
#include <string.h>

using namespace std;

class HomeWork {
    friend ostream& operator<<(ostream&, const HomeWork);

    private:
        string task;
        int minutesTaken;

    public:
        HomeWork(string = "", int = 0);
        HomeWork operator+(HomeWork);
};

ostream& operator<<(ostream& out, HomeWork hw) {
    out << endl;
    out << "Task: " << hw.task << endl;
    out << "Minutes: " << hw.minutesTaken << endl;
    return out;
}

HomeWork::HomeWork(string task, int minutes) {
    this->task = task;
    this->minutesTaken = minutes;
}

HomeWork HomeWork::operator+(HomeWork hw) {
    HomeWork temp;
    temp.task = "Mixed";
    temp.minutesTaken = this->minutesTaken + hw.minutesTaken;
    return temp;  
}

template <class T> 
T addTwo(T objA, T objB) {
    return objA + objB;
}

int main() {
    HomeWork HWA("Do task 3", 45);
    HomeWork HWB("Do task 5", 45);
    HomeWork HWC("Do task 2", 45);
    HomeWork result;

    result = addTwo(HWA, HWB);
    result = addTwo(result, HWC);

    cout << "Sum: " << result << endl;
}