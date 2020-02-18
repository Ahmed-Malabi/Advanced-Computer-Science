CXXFLAGS += --std=c++17

all: main
debug: CXXFLAGS += -g
debug: main

rebuild: clean main


main: test.o coin.o *.h
	$(CXX) $(CXXFLAGS) -o main test.o coin.o
	
test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c test.cpp
	
coin.o: coin.cpp * .h
	$(CXX) $(CXXFLAGS) -c coin.cpp
	
clean:
	-rm -f *.o *.gch *~ main
