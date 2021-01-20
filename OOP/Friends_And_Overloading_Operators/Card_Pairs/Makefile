CXX = g++
CXXFLAGS = -Wall

main: main.o Hand.o PlayingCard.o PlayingDeck.o
	$(CXX) $(CXXFLAGS) -o main main.o Hand.o PlayingCard.o PlayingDeck.o

main.o: Hand.h PlayingDeck.h

Hand.o: Hand.h PlayingDeck.h PlayingCard.h

PlayingCard.o: PlayingCard.h 

PlayingDeck.o: PlayingDeck.h PlayingCard.h

clean:
	rm *.o