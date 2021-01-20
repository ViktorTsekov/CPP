CXX = g++

main: main.o House.o Investment.o HouseInvestment.o
	$(CXX) -o main main.o House.o Investment.o HouseInvestment.o

main.o: HouseInvestment.h 

House.o: House.h 

Investment.o: Investment.h 

HouseInvestment.o: HouseInvestment.h

clean:
	rm *.o