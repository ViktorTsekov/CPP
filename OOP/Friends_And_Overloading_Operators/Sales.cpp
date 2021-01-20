#include <iostream>
#include <string.h>

using namespace std;

class Sale;
class Salesperson;

class Sale {
    friend void display(Sale, Salesperson);

    private:
        int day;
        int saleAmount;
        string saleID;

    public:
        Sale(int, int, string);
};

class Salesperson {
    friend void display(Sale, Salesperson);
    friend string getSalespersonID(Salesperson);

    private: 
        string salespersonID;
        string lastName;
    
    public:
        Salesperson(string, string);
};

Sale::Sale(int day, int saleAmount, string saleID) {
    this->day = day;
    this->saleAmount = saleAmount;
    this->saleID = saleID;
}

Salesperson::Salesperson(string salespersonID, string lName) {
    this->salespersonID = salespersonID;
    this->lastName = lName;
}

void display(Sale sale, Salesperson salesperson) {
    cout << endl;
    cout << sale.day << endl;
    cout << sale.saleAmount << endl;
    cout << sale.saleID << endl;
    cout << salesperson.salespersonID << endl;
    cout << salesperson.lastName << endl; 
}

string getSalespersonID(Salesperson salesperson) {
    return salesperson.salespersonID;
}

int main() {
    Sale sale(28, 1200, "69420565");
    Salesperson salesperson("28001040", "Tsekov");

    display(sale, salesperson);
    cout << "ID: " << getSalespersonID(salesperson) << endl;
}