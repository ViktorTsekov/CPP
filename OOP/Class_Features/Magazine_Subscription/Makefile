CXX = g++
CXXFLAGS = -Wall -g

main: main.o Name.o Person.o CreditData.o Date.o MagazineSubscription.o 
	$(CXX) $(CXXFLAGS) -o main main.o Name.o Person.o CreditData.o Date.o MagazineSubscription.o 

main.o: Name.h Person.h CreditData.h Date.h MagazineSubscription.h

MagazineSubscription.o: MagazineSubscription.h Person.h Date.h

Person.o: Person.h CreditData.h Name.h

CreditData.o: CreditData.h

Date.o: Date.h

Name.o: Name.h

clean:
	rm *.o