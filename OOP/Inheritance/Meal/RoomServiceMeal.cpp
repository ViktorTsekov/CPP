#include "RoomServiceMeal.h"

const double RoomServiceMeal::SERVICEFEE = 3.99;
const string RoomServiceMeal::SERVICENAME  = "Room Service";

RoomServiceMeal::RoomServiceMeal(string mealName, string roomNumber, double mealPrice):
    HotelService(SERVICENAME, roomNumber, SERVICEFEE),
    RestaurantMeal(mealName, mealPrice) { }

void RoomServiceMeal::displayOrder() {
    double total = SERVICEFEE + getMealPrice();
    displayMeal();
    displayService();
    cout << "Total Price: " << total << endl;
}