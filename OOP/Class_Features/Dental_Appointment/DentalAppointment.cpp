#include "DentalAppointment.h"

DentalAppointment::DentalAppointment(string fName, string lName, int day, int month, int year, int hour, int minutes, int duration):
patient(fName, "", lName, 0, 0, ""),
appointmentDate(day, month, year),
appointmentHour(hour, minutes),
endAppointmentHour(hour, minutes) {
    if(duration > 240) {
        durationOfAppointment = 240;
        cout << "Duration can not be more than 240 minutes" << endl;
    } else {
        durationOfAppointment = duration;
    }
}

void DentalAppointment::calculateEndHour() {
    endAppointmentHour.addMinutes(durationOfAppointment);
}

void DentalAppointment::displayData() {
    cout << "Patient: "; patient.showName();
    cout << "Appointment date: "; appointmentDate.displayDate();
    cout << "Beginning of appointment: "; appointmentHour.displayTime();
    cout << "End of appointment: "; endAppointmentHour.displayTime();
}