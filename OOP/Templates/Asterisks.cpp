#include <iostream>
#include <string.h>

using namespace std;

class Asterisks {
    public:
        template <class T>
            void displayWithAsterisks(T);
};

class Employee {
    friend ostream& operator<<(ostream&, const Employee&);

    private:
        string firstName;
        string lastName;
        string ID;

    public:
        Employee(string, string, string);
};

template <class T>
void Asterisks::displayWithAsterisks(T arg) {
    cout << arg << endl;
    cout << "************" << endl;
}

ostream& operator<<(ostream& out, const Employee& empl) {
    out << "First name: " << empl.firstName << endl;
    out << "Last name: " << empl.lastName << endl;
    out << "ID: " << empl.ID << endl;

    return out;
}

Employee::Employee(string fName, string lName, string anID) {
    firstName = fName;
    lastName = lName;
    ID = anID;
}

int main() {
    Asterisks ast;
    Employee empl("Viktor", "Tsekov", "28001040");
    int val = 69;

    ast.displayWithAsterisks(val);
    ast.displayWithAsterisks(empl);
}