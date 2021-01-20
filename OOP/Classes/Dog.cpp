#include <iostream>
#include <string.h>

using namespace std;

class Dog {
    private:
        string name;
        string breed;
        int age;
        const double licenseFee;

    public:
        Dog(double theLicenseFee) : licenseFee(theLicenseFee) {}
        void setData();
        void displayData();
};

void Dog::setData() {
    string strExpression;
    int intExpression;

    cout<<"Set name: "; cin>>strExpression; name = strExpression;
    cout<<"Set breed: "; cin>>strExpression; breed = strExpression;
    cout<<"Set age: "; cin>>intExpression; age = intExpression;
}

void Dog::displayData() {
    cout<<"\nName: " <<name <<endl;
    cout<<"Breed: " <<breed <<endl;
    cout<<"Age: " <<age <<endl;
    cout<<"License fee: " <<licenseFee <<endl;
}

int main() {
    Dog dog(12.25);
    dog.setData();
    dog.displayData();
}