CXX = g++
CXXFLAGS = -Wall

main: main.o Rectangle.o Block.o
	$(CXX) $(CXXFLAGS) -o main main.o Rectangle.o Block.o

main.o: Rectangle.h Block.h

Rectangle.o: Rectangle.h

Block.o: Rectangle.h Block.h

clean:
	rm *.o