# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g

# Targets needed to bring the executable up to date

main: main.o Fraction.o MathProblem.o RandomNumbers.o UserTest.o DoublingMathProblem.o
	$(CXX) $(CXXFLAGS) -o main main.o Fraction.o MathProblem.o RandomNumbers.o UserTest.o DoublingMathProblem.o

# The main.o target can be written more simply

main.o: UserTest.h

Fraction.o: Fraction.h

MathProblem.o: MathProblem.h Fraction.h

RandomNumbers.o: RandomNumbers.h

UserTest.o: UserTest.h MathProblem.h Fraction.h RandomNumbers.h DoublingMathProblem.h

DoublingMathProblem.o: DoublingMathProblem.h

# Here we clear the old object files

clean:
	rm *.o