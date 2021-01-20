#ifndef HOTELSERVICE
#define HOTELSERVICE

#include <iostream>
#include <string.h>

using namespace std;

class HotelService {
    private:
        string serviceName;
        string roomNumber;
        double serviceFee;

    public:
        HotelService(string = "", string = "", double = 0);
        void displayService();
};

#endif