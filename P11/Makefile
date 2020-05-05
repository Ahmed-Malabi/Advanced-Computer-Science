CXXFLAGS += --std=c++17

all: main debug test


debug: CXXFLAGS += -g
debug: clean main

rebuild: clean main

main: item.o cart.o
	$(CXX) $(CXXFLAGS) -o main item.o cart.o
	
Main.o: Main.cpp
	$(CXX) $(CXXFLAGS) -c Main.cpp
	
Product.o: item.cpp
	$(CXX) $(CXXFLAGS) -c item.cpp
	
Taxed.o: cart.cpp
	$(CXX) $(CXXFLAGS) -c cart.cpp
	
clean:
	-rm -f *.o *.gch *~ main
