#ifndef DENTALAPPOINTMENT
#define DENTALAPPOINTMENT

#include <iostream>
#include <string.h>

#include "Person.h"
#include "Date.h" 
#include "Time.h"

using namespace std;

class DentalAppointment {
    private:
        Person patient;
        Date appointmentDate;
        Time appointmentHour;
        Time endAppointmentHour;
        int durationOfAppointment;

    public:
        DentalAppointment(string fName, string lName, int day, int month, int year, int hour, int minutes, int duration = 30);
        void calculateEndHour();
        void displayData();
};

#endif