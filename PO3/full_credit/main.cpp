#include "color.h"
#include <iostream>
#include <string>

int main()
{
	//int r, g, b;
	Color red{255,0,0};
	Color purple{200,40,200};
	Color orange{225,140,40};
	
	std::cout << red << "RED" << Color{} << purple << "PURPLE" << Color{} << orange << "ORANGE" << Color{} <<std::endl;
	
	Color userC{0,0,0};
	std::cout << "Enter a value 0-255 for red, green and blue \"(RED, GREEN, BLUE)\")" << std::endl, std::cin >> userC;
	
	std::cout << userC << "Hello I am your color!" << Color{} << std::endl;

	return 0;
}

