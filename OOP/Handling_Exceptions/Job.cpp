#include <iostream>
#include <string.h>

using namespace std;

class Job {
    friend ostream& operator<<(ostream&, const Job);
    friend istream& operator>>(istream&, Job&);

    private:
        string jobID;
        int cost;
};

ostream& operator<<(ostream& out, const Job job) {
    out << endl;
    out << "Job ID: " << job.jobID << endl;
    out << "Cost: " << job.cost << endl;
    out << "-------------------" << endl;

    return out;
}

istream& operator>>(istream& in, Job& job) {
    int costTemp;

    cout << endl;
    cout << "Enter ID: "; in >> job.jobID;
    cout << "Enter cost: "; cin >> costTemp;

    if(costTemp < 250) {
        runtime_error e("Fee too low. No fees lower than 250 allowed. Try entering again.");
        throw(e);
    } else {
        job.cost = costTemp;
    }

    return in;
}

int main() {
    Job jobs[5];

    for (int i = 0; i < 5; i++) {
        cout << "\nJob #" << i + 1 << endl;

        try {
            cin >> jobs[i];
        } catch(runtime_error e) {
            cout << e.what() << endl;
            i--;
        }
    }

    for(int i  = 0; i < 5; i++) {
        cout << jobs[i];
    }
}