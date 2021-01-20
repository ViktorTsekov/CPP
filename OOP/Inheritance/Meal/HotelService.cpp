#include "HotelService.h"

HotelService::HotelService(string name, string number, double fee) {
    serviceName = name;
    roomNumber = number;
    serviceFee = fee;
}

void HotelService::displayService() {
    cout << "Service: " << serviceName << endl;
    cout << "Room Number: " << roomNumber << endl;
    cout << "Fee: " << serviceFee << endl;
}