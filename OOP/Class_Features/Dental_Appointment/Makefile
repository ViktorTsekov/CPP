CXX = g++
CXXFLAGS = -Wall -g

main: main.o CreditData.o Date.o DentalAppointment.o Name.o Person.o Time.o
	$(CXX) $(CXXFLAGS) -o main main.o CreditData.o Date.o DentalAppointment.o Name.o Person.o Time.o

main.o: DentalAppointment.h

CreditData.o: CreditData.h

Date.o: Date.h

DentalAppointment.o: DentalAppointment.h

Name.o: Name.h

Person.o: Person.h

Time.o: Time.h

clean:
	rm *.o