#include <iostream>
#include <string.h>

using namespace std;

class RealEstate {
    friend ostream& operator<<(ostream&, const RealEstate&);
    friend istream& operator>>(istream&, RealEstate&);

    private:
        int housePrice;
        int numOfBathrooms;
        int numOfBedrooms;

    public:
        void setFieldsToZero();
};

istream& operator>>(istream& in, RealEstate& realEstate) {
    int input;
    const runtime_error NON_INTEGER_DATA("Non-integer data entered!");
    const out_of_range OUT_OF_RANGE("Negative data entered!");

    cout << "Enter house price: "; cin >> input;
    if(!input) {
        throw(NON_INTEGER_DATA);
    } else if(input < 0) {
        throw(OUT_OF_RANGE);
    } else {
        realEstate.housePrice = input;
    }

    cout << "Enter number of bathrooms: "; cin >> input;
    if(!input) {
        throw(NON_INTEGER_DATA);
    } else if(input < 0) {
        throw(OUT_OF_RANGE);
    } else {
        realEstate.numOfBathrooms = input;
    }

    cout << "Enter number of bedrooms: "; cin >> input;
    if(!input) {
        throw(NON_INTEGER_DATA);
    } else if(input < 0) {
        throw(OUT_OF_RANGE);
    } else {
        realEstate.numOfBedrooms = input;
    }

    return in;
}

ostream& operator<<(ostream& out, const RealEstate& realEstate) {
    cout << "House price: " << realEstate.housePrice << endl;
    cout << "Number of bathrooms: " << realEstate.numOfBathrooms << endl;
    cout << "Number of bedrooms: " << realEstate.numOfBedrooms << endl; 

    return out;
}

void RealEstate::setFieldsToZero() {
    housePrice = 0;
    numOfBathrooms = 0;
    numOfBedrooms = 0;
}

int main() {
    RealEstate house;

    try {
        cin >> house;
    } catch(runtime_error e) {
        cout << e.what() << endl;
        house.setFieldsToZero();
    } catch(out_of_range e) {
        cout << e.what() << endl;
        house.setFieldsToZero();
    }

    cout << endl << house;
}