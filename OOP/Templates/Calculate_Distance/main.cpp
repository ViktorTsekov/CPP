#include "CalculateDistance.h"
#include "City.h"

int main() {
    City cityA(5000, "LA");
    City cityB(6000, "Washington");
    CalculateDistance calc;

    cout << "Double + Double arguments: " << calc.calculateDistance(5.9, 5.8) << endl;
    cout << "The distance from " << cityA.getCityName() << " to " << cityB.getCityName() << " is " << calc.calculateDistance(cityA, cityB) << " km\n";
}