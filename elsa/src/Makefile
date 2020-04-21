CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: main


debug: CXXFLAGS += -g
debug: clean main

rebuild: clean main


main: Main.o Store.o Order.o Customer.o Desktop.o Options.o Ram.o Mainwin.o Entrydialog.o
	$(CXX) $(CXXFLAGS) Main.o Store.o Order.o Customer.o Desktop.o Options.o Ram.o Mainwin.o Entrydialog.o $(GTKFLAGS) -o main
	
Main.o: Main.cpp *.h
	$(CXX) $(CXXFLAGS) -c Main.cpp $(GTKFLAGS) -o Main.o
	
Store.o: Store.cpp *.h
	$(CXX) $(CXXFLAGS) -c Store.cpp
	
Order.o: Order.cpp *.h
	$(CXX) $(CXXFLAGS) -c Order.cpp
	
Customer.o: Customer.cpp *.h
	$(CXX) $(CXXFLAGS) -c Customer.cpp
	
Desktop.o: Desktop.cpp *.h
	$(CXX) $(CXXFLAGS) -c Desktop.cpp

Options.o: Options.cpp *.h
	$(CXX) $(CXXFLAGS) -c Options.cpp
	
Ram.o: Ram.cpp *.h
	$(CXX) $(CXXFLAGS) -c Ram.cpp
	
Mainwin.o: Mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c Mainwin.cpp $(GTKFLAGS) -o Mainwin.o
	
Entrydialog.o: Entrydialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c Entrydialog.cpp $(GTKFLAGS) -o Entrydialog.o
	
clean:
	-rm -f *.o *.gch *~ main
