#ifndef MEAL
#define MEAL

#include <iostream>
#include <string.h>

#include "OutOfRange.h"

class Meal {
    friend ostream& operator<<(ostream& out, const Meal& meal);

    private:
        string mealName;
        double price;

    public:
        double getPrice();
        void setData();
        void displayData();
};

#endif