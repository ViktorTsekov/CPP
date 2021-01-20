# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g

# Targets needed to bring the executable up to date

main: main.o Name.o StudentGrade.o
	$(CXX) $(CXXFLAGS) -o main main.o Name.o StudentGrade.o

# Here we link the object files to the headers on which they depend

main.o: Name.h StudentGrade.h 

Name.o: Name.h

StudentGrade.o: Name.h StudentGrade.h 

# Here we clear the old object files

clean:
	rm *.o