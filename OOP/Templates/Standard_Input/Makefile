CXX = g++

main: main.o CollegeCourse.o
	$(CXX) -o main main.o CollegeCourse.o

main.o: CollegeCourse.h StandardInput.h

CollegeCourse.o: CollegeCourse.h

clean:
	rm *.o