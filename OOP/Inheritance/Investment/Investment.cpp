#include "Investment.h"

Investment::Investment(double initValue, double curValue) {
    initialValue = initValue;
    currentValue = curValue;
    profit = currentValue - initialValue;
    percentProfit = (profit / initialValue) * 100;
}

void Investment::displayInvestment() {
    cout << "Initial investment: " << initialValue << endl;
    cout << "Current value: " << currentValue << endl;
    cout << "Profit: " << percentProfit << "%" << endl;
}