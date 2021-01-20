#include <iostream>
#include <string.h>

using namespace std;

class Employee {
    private:
        string name;
        string phoneNumber;
        double payRate;
        unsigned bit1:1;
        unsigned bit2:1;
        unsigned bit3:1;
        unsigned bit4:1;
        unsigned bit5:1;
        unsigned bit6:1;

    public:
        Employee() {};
        Employee(int, int, int, int, int, int);
        Employee(string, string, double, int, int, int, int, int, int);
        Employee operator&(Employee);
        int convertBits();
        void displayBits();
};

Employee::Employee(int bit1, int bit2, int bit3, int bit4, int bit5, int bit6) {
    this->bit1 = bit1;
    this->bit2 = bit2;
    this->bit3 = bit3;
    this->bit4 = bit4;
    this->bit5 = bit5;
    this->bit6 = bit6;
}

Employee::Employee(string name, string phone, double payRate, int bit1, int bit2, int bit3, int bit4, int bit5, int bit6) {
    this->name = name;
    this->phoneNumber = phone;
    this->payRate = payRate;
    this->bit1 = bit1;
    this->bit2 = bit2;
    this->bit3 = bit3;
    this->bit4 = bit4;
    this->bit5 = bit5;
    this->bit6 = bit6;
}

Employee Employee::operator&(Employee ref) {
    Employee temp;
    temp.bit1 = this->bit1 & ref.bit1;
    temp.bit2 = this->bit2 & ref.bit2;
    temp.bit3 = this->bit3 & ref.bit3;
    temp.bit4 = this->bit4 & ref.bit4;
    temp.bit5 = this->bit5 & ref.bit5;
    temp.bit6 = this->bit6 & ref.bit6;

    return temp;
}

int Employee::convertBits() {
    int temp = bit1 * 2 +
               bit2 * 4 +
               bit3 * 8 +
               bit4 * 16 +
               bit5 * 32 +
               bit6 * 64;

    return temp;
}

void Employee::displayBits() {
    cout << bit1 << bit2 << bit3 << bit4 << bit5 << bit6 << endl;
}

int main() {
    //22 is the code for good employee
    const Employee goodEmployeeMask(1, 1, 0, 1, 0, 0);
    Employee employee("Viktor", "0893284282", 9.75, 1, 1, 0, 0, 0, 0);
    Employee temp;
      
    temp = goodEmployeeMask;
    temp = temp & employee;

    if(temp.convertBits() == 22) {
        cout << "The employee is good\n";
    } else {
        cout << "The employee is not good\n";
    }
    
}