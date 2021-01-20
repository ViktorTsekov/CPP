CXX = g++

main: main.o Inventory.o
	$(CXX) -o main main.o Inventory.o

main.o: Inventory.h

Inventory.o: Inventory.h

clean:
	rm *.o