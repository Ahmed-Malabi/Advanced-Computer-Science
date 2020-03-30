CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: main debug customer options desktop order store


debug: CXXFLAGS += -g
debug: clean main

rebuild: clean main


main: Main.o Store.o Order.o Customer.o Desktop.o Options.o
	$(CXX) $(CXXFLAGS) Main.o Store.o Order.o Customer.o Desktop.o Options.o $(GTKFLAGS) -o main
	
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
