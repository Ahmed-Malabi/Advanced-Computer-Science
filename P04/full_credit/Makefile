CXXFLAGS += --std=c++17

all: main debug logger


debug: CXXFLAGS += -g
debug: main

logger: CXXFLAGS += -DLOGGER
logger: main

rebuild: clean main


main: test.o coin.o
	$(CXX) $(CXXFLAGS) -o main test.o coin.o
	
test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c test.cpp
	
coin.o: coin.cpp
	$(CXX) $(CXXFLAGS) -c coin.cpp
	
clean:
	-rm -f *.o *.gch *~ main
