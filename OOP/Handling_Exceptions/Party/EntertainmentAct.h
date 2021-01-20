#ifndef ENTERTAINMENT
#define ENTERTAINMENT

#include <iostream>
#include <string.h>

#include "OutOfRange.h"

class EntertainmentAct {
    friend ostream& operator<<(ostream&, const EntertainmentAct);

    private:
        string phoneNumber;
        double fee;

    public:
        void setData();
        double getFee();
};

#endif