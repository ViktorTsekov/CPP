CXX = g++

main: main.o Book.o Fiction.o NonFiction.o
	$(CXX) -o main main.o Book.o Fiction.o NonFiction.o

main.o: Book.h Fiction.h NonFiction.h

Book.o: Book.h

Fiction.o: Book.h Fiction.h

NonFiction.o: Book.h NonFiction.h

clean:
	rm *.o