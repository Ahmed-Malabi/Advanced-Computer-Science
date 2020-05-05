CXXFLAGS += --std=c++17

all: main debug


debug: CXXFLAGS += -g
debug: clean main

rebuild: clean main

main: main.o item.o cart.o
	$(CXX) $(CXXFLAGS) -o main main.o item.o cart.o
	
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp
	
item.o: item.cpp
	$(CXX) $(CXXFLAGS) -c item.cpp
	
cart.o: cart.cpp
	$(CXX) $(CXXFLAGS) -c cart.cpp
	
clean:
	-rm -f *.o *.gch *~ main
