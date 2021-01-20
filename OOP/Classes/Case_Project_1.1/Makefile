# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g

# Targets needed to bring the executable up to date

main: main.o Fraction.o
	$(CXX) $(CXXFLAGS) -o main main.o Fraction.o

# The main.o target can be written more simply

main.o: main.cpp Fraction.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Fraction.o: Fraction.h

# Here we clear the old object files

clean:
	rm *.o