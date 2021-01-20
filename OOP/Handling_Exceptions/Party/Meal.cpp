#include "Meal.h"

ostream& operator<<(ostream& out, const Meal& meal) {
    out << endl << "Meal plan:\n";
    out << meal.mealName << " for " << meal.price;
    return out;
}

double Meal::getPrice() {
    return price;
}

void Meal::setData() {
    double doubleInput;
    OutOfRange e(5, 29.99);

    cout << "Set meal name: "; cin >> mealName;
    cout << "Set meal price: "; cin >> doubleInput;

    if(e.theValueIsBad(doubleInput)) {
        e.setBadNumber(doubleInput);
        throw(e);
    } else {
        price = doubleInput;
    }

}