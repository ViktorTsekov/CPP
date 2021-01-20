CXX = g++

main: main.o CollegeCourse.o
	$(CXX) -o main main.o CollegeCourse.o

main.o: Average.h CollegeCourse.h

CollegeCourse.o: CollegeCourse.h

clean:
	rm *.o