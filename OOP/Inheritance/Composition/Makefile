CXX = g++

main: main.o MusicalComposition.o NationalAnthem.o
	$(CXX) -o main main.o MusicalComposition.o NationalAnthem.o

main.o: NationalAnthem.h

MusicalComposition: MusicalComposition.h

NationalAnthem: MusicalComposition NationalAnthem.h

clean:
	rm *.o