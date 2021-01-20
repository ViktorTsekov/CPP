#include "RestaurantMeal.h"

RestaurantMeal::RestaurantMeal(string mealName, double price) {
    this->mealName = mealName;
    this->price = price;
}

double RestaurantMeal::getMealPrice() {
    return price;
}

void RestaurantMeal::displayMeal() {
    cout << "Meal: " << mealName << endl;
    cout << "Price: " << price << endl;
}