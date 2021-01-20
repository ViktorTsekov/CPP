#ifndef RESTAURANTMEAL
#define RESTAURANTMEAL

#include <iostream>
#include <string.h>

using namespace std;

class RestaurantMeal {
    private:
        string mealName;
        double price;

    public:
        double getMealPrice();
        RestaurantMeal(string = "", double = 0);
        void displayMeal();
};

#endif