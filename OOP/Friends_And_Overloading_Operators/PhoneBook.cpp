#include <iostream>
#include <string>

using namespace std;

class PhoneBook {
    friend ostream& operator<<(ostream&, const PhoneBook&);
    friend istream& operator>>(istream&, PhoneBook&);

    private:
        string firstName;
        string lastName;
        string areaCode;
        string phoneNumber;

    public:
        PhoneBook& operator()(string, string);
        PhoneBook& operator[](string);
};

ostream& operator<<(ostream& out, const PhoneBook& phoneBook) {
    out << endl;
    out << "First name: " << phoneBook.firstName << endl;
    out << "Last name: " << phoneBook.lastName << endl;
    out << "Area code: " << phoneBook.areaCode << endl;
    out << "Phone number: " << phoneBook.phoneNumber << endl;
    out << endl;

    return out;
}

istream& operator>>(istream& in, PhoneBook& phoneBook) {
    cout << endl;
    cout << "Enter first name: "; in >> phoneBook.firstName;
    cout << "Enter last name: "; in >> phoneBook.lastName;
    cout << "Enter area code: "; in >> phoneBook.areaCode;
    cout << "Enter phone number: "; in >> phoneBook.phoneNumber;
    cout << endl;

    return in;
}

PhoneBook& PhoneBook::operator()(string areaCode, string phoneNumber) {
    this->areaCode = areaCode;
    this->phoneNumber = phoneNumber;

    return *this;
}

PhoneBook& PhoneBook::operator[](string phoneNumber) {
    this->phoneNumber = phoneNumber;

    return *this;
}

int main() {
    PhoneBook phoneBooks[3];

    for(int i = 0; i < 3; i++) {
        static int num = 1;
        cout << "Entry " << num << ":"; num++;
        cin >> phoneBooks[i];
    }

    for(int i = 0; i < 3; i++) {
        static int num = 1;
        cout << "Entry " << num << ":"; num++;
        cout << phoneBooks[i];
    }

    int input;
    string defaultCharacter = "...";

    cout << "You will alter the data of the first entry!" << endl;
    cout << "Press 0 to set phone number and area code to default. Press 1 to set only phone number to default." << endl;
    cout << "Input: "; cin >> input; cout << endl;

    switch(input) {
        case 0: phoneBooks[0](defaultCharacter, defaultCharacter); break;
        case 1: phoneBooks[0][defaultCharacter]; break;
        default: cout << "Invalid input bitch!" << endl; break;
    }

    for(int i = 0; i < 3; i++) {
        static int num = 1;
        cout << "Entry " << num << ":"; num++;
        cout << phoneBooks[i];
    }

}