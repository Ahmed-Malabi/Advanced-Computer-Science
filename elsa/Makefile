CXXFLAGS += --std=c++17

all: main debug customer options


debug: CXXFLAGS += -g
debug: clean main

rebuild: clean main


main: Main.o Store.o Order.o Customer.o Desktop.o Options.o
	$(CXX) $(CXXFLAGS) -o main Main.o Store.o Order.o Customer.o Desktop.o Options.o
	
customer: CustomerTest.o Customer.o
	$(CXX) $(CXXFLAGS) -o customer CustomerTest.o Customer.o
	
options: OptionsTest.o Options.o
	$(CXX) $(CXXFLAGS) -o options OptionsTest.o Options.o
	
Main.o: Main.cpp
	$(CXX) $(CXXFLAGS) -c Main.cpp
	
Store.o: Store.cpp
	$(CXX) $(CXXFLAGS) -c Store.cpp
	
Order.o: Order.cpp
	$(CXX) $(CXXFLAGS) -c Order.cpp
	
Customer.o: Customer.cpp
	$(CXX) $(CXXFLAGS) -c Customer.cpp
	
Desktop.o: Desktop.cpp
	$(CXX) $(CXXFLAGS) -c Desktop.cpp

Options.o: Options.cpp
	$(CXX) $(CXXFLAGS) -c Options.cpp
	
clean:
	-rm -f *.o *.gch *~ main
