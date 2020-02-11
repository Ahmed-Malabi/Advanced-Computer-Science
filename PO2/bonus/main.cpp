#include "color.h"
#include <iostream>
#include <string>

int main()
{	
	Color test{255,255,255};
	Color comp(180,200,90);
	
	std::cout << test.colorize(test.Color::to_string()) << "\n"<<comp.colorize(comp.Color::to_string()) << "\n" << "Comparing left magnitude to right magnitude (1 greater, 0 equal, -1 less): " << std::to_string(test.compare(comp)) << std::endl;
	
	return 0;
}

