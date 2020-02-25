CXXFLAGS += --std=c++17

all: main debug


debug: CXXFLAGS += -g
debug: clean main

rebuild: clean main


main: Main.o Product.o Taxed.o Taxfree.o
	$(CXX) $(CXXFLAGS) -o main Main.o Product.o Taxed.o Taxfree.o
	
Main.o: Main.cpp
	$(CXX) $(CXXFLAGS) -c Main.cpp
	
Product.o: Product.cpp
	$(CXX) $(CXXFLAGS) -c Product.cpp
	
Taxed.o: Taxed.cpp
	$(CXX) $(CXXFLAGS) -c Taxed.cpp
	
Taxfree.o: Taxfree.cpp
	$(CXX) $(CXXFLAGS) -c Taxfree.cpp
	
clean:
	-rm -f *.o *.gch *~ main
