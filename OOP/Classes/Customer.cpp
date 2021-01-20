#include <iostream>
#include <string.h>

using namespace std;

class Customer {
    private:
        string ID;
        string firstName;
        string lastName;
        int creditLimit;
    
    public:
        void setID(string);
        void setFirstName(string);
        void setLastName(string);
        bool setCreditLimit(int);
        void display();
};

void Customer::setID(string theID) {
    ID = theID;
}

void Customer::setFirstName(string theFirstName) {
    firstName = theFirstName;
}

void Customer::setLastName(string theLastName) {
    lastName = theLastName;
}

bool Customer::setCreditLimit(int theLimit) {
    if(theLimit > 10000) {
        cout<< "Credit limit over 10000 not allowed"<< endl;
        return false;
    } else {
        creditLimit = theLimit;
    }

    return true;
}

void Customer::display(){
    cout<<"ID: " <<ID <<endl;
    cout<<"First name: " <<firstName <<endl;
    cout<<"Last name: " <<lastName <<endl;
    cout<<"Credit limit: " <<creditLimit <<endl;
}

int main() {
    Customer customers[5];
    string strExpression;
    int intExpression;

    cout<<"Enter five customers\n\n";

    for(int i = 0; i < 5; i++) {
        cout<<"Enter 8 digit ID: ";
        cin>>strExpression;
        customers[i].setID(strExpression);

        cout<<"Enter first name: ";
        cin>>strExpression;
        customers[i].setFirstName(strExpression);

        cout<<"Enter last name: ";
        cin>>strExpression;
        customers[i].setLastName(strExpression);

        cout<<"Enter credit limit: ";
        cin>>intExpression;
        while(!customers[i].setCreditLimit(intExpression)) {
            cout<<"Try again: ";
            cin>>intExpression;
        }

        cout<<endl;
    }

    for(int i = 0; i < 5; i++) {
        customers[i].display();
        cout<<endl;
    }

}