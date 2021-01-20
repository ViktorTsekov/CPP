CXX = g++

main: main.o Arcade.o RandomNumbers.o User.o
	$(CXX) -o main main.o Arcade.o RandomNumbers.o User.o

main.o: User.h Arcade.h

Arcade.o: Arcade.h User.h RandomNumbers.h

RandomNumbers.o: RandomNumbers.h

User.o: User.h

clean:
	rm *.o