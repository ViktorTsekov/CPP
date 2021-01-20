CXX = g++
CXXFLAGS = -Wall

main: main.o Hand.o PlayingCard.o
	$(CXX) $(CXXFLAGS) -o main main.o Hand.o PlayingCard.o

main.o: Hand.h 

Hand.o: Hand.h

PlayingCard.o: PlayingCard.h 

clean:
	rm *.o