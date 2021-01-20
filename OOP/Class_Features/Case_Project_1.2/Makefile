# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g

# Targets needed to bring the executable up to date

main: main.o Fraction.o MathProblem.o
	$(CXX) $(CXXFLAGS) -o main main.o Fraction.o MathProblem.o

# The main.o target can be written more simply

main.o: Fraction.h

Fraction.o: Fraction.h

MathProblem.o: MathProblem.h

# Here we clear the old object files

clean:
	rm *.o