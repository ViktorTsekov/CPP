#include "HouseInvestment.h"

HouseInvestment::HouseInvestment(double initValue, double curValue, string address, int sqFeet):
    Investment(initValue, curValue),
    House(address, sqFeet) { }

void HouseInvestment::displayHouseInvestment() {
    displayInvestment();
    displayHouse();
}