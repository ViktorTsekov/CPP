#include <iostream>
#include <string.h>

using namespace std;

class Jobbid {
    friend ostream& operator<<(ostream&, const Jobbid&);
    friend istream& operator>>(istream&, Jobbid&);

    private:
        int bidNumber;
        double price;

    public:
        Jobbid(int, double);
        bool operator<(Jobbid);
        bool operator>(Jobbid);
        bool operator==(Jobbid);
};

ostream& operator<<(ostream& output, const Jobbid& jobbid) {
    output << endl;
    output << "Bid number: " << jobbid.bidNumber << endl;
    output << "Cur. price: " << jobbid.price << endl;

    return output;
}

istream& operator>>(istream& input, Jobbid& jobbid) {
    cout << endl;
    cout << "Enter bid number: "; input >> jobbid.bidNumber;
    cout << "Enter price: "; input >> jobbid.price;

    return input;
}

Jobbid::Jobbid(int bidNumber, double price) {
    this->bidNumber = bidNumber;
    this->price = price;
}

bool Jobbid::operator<(Jobbid jobbid) {
    return price < jobbid.price;
}

bool Jobbid::operator>(Jobbid jobbid) {
    return price > jobbid.price;
}

bool Jobbid::operator==(Jobbid jobbid) {

    if(bidNumber == jobbid.bidNumber) {
        cout << "Two same id's cannot exist" << endl;
        exit(1);
    }

    return price == jobbid.price;
}

int main() {
    Jobbid jobbidA(58, 2000);
    Jobbid jobbidB(69, 2500);

    cin >> jobbidA;

    cout << jobbidA;
    cout << jobbidB;
    
    if(jobbidA == jobbidB) {
        cout << endl << "A is equal to B" << endl;
    } else if(jobbidA < jobbidB) {
        cout << endl << "A is not bigger than B" << endl;
    } else if(jobbidA > jobbidB) {
        cout << endl << "A is bigger than B" << endl;
    }

}