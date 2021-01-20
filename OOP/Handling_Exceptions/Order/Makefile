CXX = g++

main: main.o Exception.o Order.o 
	$(CXX) -o main main.o Exception.o Order.o 

main.o: Order.h

Exception.o: Exception.h

Order.o: Order.h Exception.h

clean:
	rm *.o