#ifndef OUTOFRANGE
#define OUTOFRANGE

#include <iostream>
#include <string.h>

using namespace std;

class OutOfRange : public out_of_range {
    private:
        double bottomBoundary;
        double upperBoundary;
        double badNumber;

    public:
        OutOfRange(double, double);
        void setBadNumber(double);
        bool theValueIsBad(double);
        void showErrorDetails() const;
};

#endif