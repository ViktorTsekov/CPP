#include <iostream>
#include <string.h>

using namespace std;

class Customer;
class City;

class Customer {
    friend void displayData(Customer, City);

    private:
        int customerNumber;
        string zipCode;
    
    public:
        Customer(int, string);
};

class City {
    friend void displayData(Customer, City);

    private:
        string name;
        string state;
        string zipCode;
    
    public:
        City(string, string, string);
};

Customer::Customer(int custNum, string zip) {
    customerNumber = custNum;
    zipCode = zip;
}

City::City(string name, string state, string zip) {
    this->name = name;
    this->state = state;
    this->zipCode = zip;
}

void displayData(Customer cust, City city) {
    cout << endl;
    cout << "Customer number: " << cust.customerNumber << endl;
    cout << "Cust. zip code: " << cust.zipCode << endl;
    cout << "City: " << city.name << endl;
    cout << "State: " << city.state << endl;
    cout << "City zip code: " << city.zipCode << endl;
}

int main() {
   Customer customer(58, "3000");
   City city("Vraca", "Vraca", "3000");

   displayData(customer, city);
}