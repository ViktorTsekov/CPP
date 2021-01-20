#include <iostream>
#include <iomanip>

using namespace std;

class Item {
    friend istream& operator>>(istream&, Item&);
    friend ostream& operator<<(ostream&, const Item);

    private:
        int stockNumber;
        double price;
        int quantity;
};

istream& operator>>(istream& in, Item& item) {
    cout << "Enter stock number: "; cin >> item.stockNumber;
    cout << "Enter price: "; cin >> item.price;
    cout << "Enter quantity: "; cin >> item.quantity;
}

ostream& operator<<(ostream& out, const Item item) {
    out << fixed;
    out.width(5);
    out << item.stockNumber << " " << item.price << " " << item.quantity << endl;
    return out;
}

int main() {
    Item item;
    Item item1;

    cin >> item;
    cin >> item1;
    cout << item;
    cout << item1;
}