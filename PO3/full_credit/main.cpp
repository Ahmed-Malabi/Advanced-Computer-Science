#include "color.h"
#include <iostream>
#include <string>

int main()
{
	int r, g, b;
	Color red{255,0,0};
	Color purple{200,40,200};
	Color orange{225,140,40};
	
	std::cout << red.colorize("red,") << " " <<  purple.colorize("purple,") << " " << orange.colorize("orange.") <<std::endl;
	
	std::cout << "Enter a value 0-255 for red" << std::endl, std::cin >> r;
	std::cout << "Enter a value 0-255 for green" << std::endl, std::cin >> g;
	std::cout << "Enter a value 0-255 for blue" << std::endl, std::cin >> b;
	
	Color userC{r,g,b};
	std::cout << userC.colorize("This is the color you created!") << std::endl;

	return 0;
}

