#include "CreditData.h"

CreditData::CreditData(double currentBalance, double maxBalance) {
    this->currentBalance = currentBalance;
    this->maxBalance = maxBalance;
}

void CreditData::displayCreditData() {
    cout << "Current balance: " << currentBalance << endl;
    cout << "Max balance: " << maxBalance << endl;
}