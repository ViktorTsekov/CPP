CXX = g++

main: main.o City.o CalculateDistance.o
	$(CXX) -o main main.o City.o CalculateDistance.o

main.o: CalculateDistance.h City.h

City.o: City.h

CalculateDistance.o: CalculateDistance.h

clean:
	rm *.o