CXX = g++
CXXFLAGS = -Wall

main: main.o HotelService.o RestaurantMeal.o RoomServiceMeal.o
	$(CXX) $(CXXFLAGS) -o main main.o HotelService.o RestaurantMeal.o RoomServiceMeal.o

main.o: RoomServiceMeal.h

HotelService.o: HotelService.h

RestaurantMeal.o: RestaurantMeal.h

RoomServiceMeal.o: RoomServiceMeal.h HotelService.h RestaurantMeal.h

clean:
	rm *.o