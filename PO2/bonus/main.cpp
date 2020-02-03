#include "color.h"
#include <iostream>
#include <string>

int main()
{
	Color red{255,0,0};
	Color purple{200,40,200};
	Color orange{225,140,40};
	
	std::cout << red.colorize("red,") << " " << std::to_string(red.magnitude()) << " " <<  purple.colorize("purple,") << " " << orange.colorize("orange.") <<std::endl;
	
	return 0;
}

