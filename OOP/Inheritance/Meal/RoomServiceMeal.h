#ifndef ROOMSERVICE
#define ROOMSERVICE

#include <iostream>
#include <string.h>

#include "RestaurantMeal.h"
#include "HotelService.h"

class RoomServiceMeal : RestaurantMeal, HotelService {
    static const double SERVICEFEE;
    static const string SERVICENAME;

    public:
        RoomServiceMeal(string = "", string = "", double = 0);
        void displayOrder();
};

#endif