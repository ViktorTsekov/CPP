CXX = g++
CXXFLAGS = -Wall

main: main.o Meal.o EntertainmentAct.o OutOfRange.o Party.o 
	$(CXX) $(CXXFLAGS) -o main main.o Meal.o EntertainmentAct.o OutOfRange.o Party.o

main.o: Party.h OutOfRange.h

Meal.o: Meal.h

EntertainmentAct.o: EntertainmentAct.h

OutOfRange.o: OutOfRange.h

Party: Party.h

clean:
	rm *.o