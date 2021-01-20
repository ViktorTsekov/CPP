#ifndef CITY
#define CITY

#include <iostream>
#include <string.h>

using namespace std;

class City {
    friend ostream& operator<<(ostream&, const City&);

    private:
        int distanceFromLosAngelos;
        string cityName;
    
    public:
        City(int, string);
        int operator+(City);
        string getCityName();
};

#endif