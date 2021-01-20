#include "DentalAppointment.h"

int main() {
    DentalAppointment dentalAppointment("Viktor", "Tsekov", 6, 6, 2020, 13, 45, 120);
    dentalAppointment.calculateEndHour();
    dentalAppointment.displayData();
}