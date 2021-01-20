#include "City.h"

City::City(int dist, string city) {
    distanceFromLosAngelos = dist;
    cityName = city;
}

int City::operator+(City city) {
    int temp;
    temp = this->distanceFromLosAngelos + city.distanceFromLosAngelos;
    return temp;
}

string City::getCityName() {
    return cityName;
}