#ifndef PERSON
#define PERSON

#include <iostream>
#include <string.h>

#include "Name.h"
#include "CreditData.h"

using namespace std;

class Person {
    private:
        Name name;
        CreditData credit;
        string phoneNumber;

    public:
        public:
        Person(string = "", string = "", string = "", double = 0, double = 0, string = "");
        void showCustomer();
        void showName();
};

#endif

