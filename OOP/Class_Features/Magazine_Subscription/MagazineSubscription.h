#ifndef MAGAZINESUBSCRIPTION
#define MAGAZINESUBSCRIPTION

#include <iostream>
#include <string>

#include "Person.h"
#include "Date.h"

using namespace std;

class MagazineSubscription {
    private:
        Person customer;
        Date startDate;
        Date expirationDate;
    
    public:
        MagazineSubscription(Person, Date, Date);
        void displayCustomer();
};

#endif