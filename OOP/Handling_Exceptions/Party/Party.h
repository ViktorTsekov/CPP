#ifndef PARTY
#define PARTY

#include <iostream>
#include <string.h>

#include "Meal.h"
#include "EntertainmentAct.h"
#include "OutOfRange.h"

using namespace std;

class Party {
    friend ostream& operator<<(ostream&, const Party);
    
    private:
        Meal meal;
        EntertainmentAct actOfChoise;
        int numOfGuests;
        double partyCost;

    public:
        void setParty();
};

#endif