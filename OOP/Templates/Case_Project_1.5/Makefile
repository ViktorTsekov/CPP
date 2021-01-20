# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g

# Targets needed to bring the executable up to date

main: main.o Fraction.o MathProblem.o RandomNumbers.o UserTest.o DoublingMathProblem.o MathProblemTemplate.o
	$(CXX) $(CXXFLAGS) -o main main.o Fraction.o MathProblem.o RandomNumbers.o UserTest.o DoublingMathProblem.o MathProblemTemplate.o

# The main.o target can be written more simply

main.o: MathProblemTemplate.h

Fraction.o: Fraction.h

MathProblem.o: MathProblem.h Fraction.h

RandomNumbers.o: RandomNumbers.h

UserTest.o: UserTest.h MathProblem.h Fraction.h RandomNumbers.h DoublingMathProblem.h

DoublingMathProblem.o: DoublingMathProblem.h

MathProblemTemplate.o: MathProblemTemplate.h Fraction.h

# Here we clear the old object files

clean:
	rm *.o