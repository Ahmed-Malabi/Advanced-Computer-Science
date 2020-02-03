#include "color.h"
#include <iostream>
#include <string>

int main()
{
	Color red{255,0,0};
	Color purple{125,0,125};
	Color orange{225,140,0};
	
	std::cout << red.colorize("red,") << " " << purple.colorize("purple,") << " " << orange.colorize("orange.") <<std::endl;
	
	return 0;
}

