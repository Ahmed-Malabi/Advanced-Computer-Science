CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: main


debug: CXXFLAGS += -g
debug: clean main

rebuild: clean main


main: Main.o Store.o Order.o Customer.o Desktop.o Options.o Mainwin.o
	$(CXX) $(CXXFLAGS) Main.o Store.o Order.o Customer.o Desktop.o Options.o Mainwin.o $(GTKFLAGS) -o main
	
Main.o: Main.cpp *.h
	$(CXX) $(CXXFLAGS) -c Main.cpp $(GTKFLAGS) -o Main.o
	
Store.o: Store.cpp *.h
	$(CXX) $(CXXFLAGS) -c Store.cpp $(GTKFLAGS) -o Store.o
	
Order.o: Order.cpp *.h
	$(CXX) $(CXXFLAGS) -c Order.cpp $(GTKFLAGS) -o Order.o
	
Customer.o: Customer.cpp *.h
	$(CXX) $(CXXFLAGS) -c Customer.cpp $(GTKFLAGS) -o Customer.o
	
Desktop.o: Desktop.cpp *.h
	$(CXX) $(CXXFLAGS) -c Desktop.cpp $(GTKFLAGS) -o Desktop.o

Options.o: Options.cpp *.h
	$(CXX) $(CXXFLAGS) -c Options.cpp $(GTKFLAGS) -o Options.o
	
Mainwin.o: Mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c Mainwin.cpp $(GTKFLAGS) -o Mainwin.o
	
clean:
	-rm -f *.o *.gch *~ main
