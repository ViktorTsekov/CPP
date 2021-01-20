#include <iostream>
#include <string.h>

using namespace std;

class Job {
    friend ostream& operator<<(ostream& output, const Job& job);
    friend istream& operator>>(istream& input, Job& job);

    private:
        int jobNumber;
        int hoursToCompleteTheJob;
        double hourlyPay;

    public:
        Job(int, int, double);
};

ostream& operator<<(ostream& output, const Job& job) {
    output << endl;
    output << "Job number: " << job.jobNumber << endl;
    output << "Hours: " << job.hoursToCompleteTheJob << endl;
    output << "Pay rate: " << job.hourlyPay << endl;
    
    return output;
}

istream& operator>>(istream& input, Job& job) {
    cout << "Enter job number: "; input >> job.jobNumber;
    cout << "Enter hours: "; input >> job.hoursToCompleteTheJob;
    cout << "Enter pay rate: "; input >> job.hourlyPay;

    return input;
}

Job::Job(int jobNumber, int hoursToCompleteTheJob, double hourlyPay) {
    this->jobNumber = jobNumber;
    this->hoursToCompleteTheJob = hoursToCompleteTheJob;
    this->hourlyPay = hourlyPay;
}

int main() {
    Job job(58, 40, 9.70);

    cin >> job;
    cout << job;
}