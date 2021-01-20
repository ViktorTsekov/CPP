CXX = g++

main: main.o RandomNumbers.o Dog.o
	$(CXX) -o main main.o RandomNumbers.o Dog.o

main.o: RandomNumbers.h

RandomNumbers.o: RandomNumbers.h

Dog.o: Dog.h RandomNumbers.h

clean:
	rm *.o