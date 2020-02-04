#include "color.h"
#include <iostream>
#include <string>

int main()
{	
	Color test{231,200,0};
	
	std::cout << test.colorize(test.Color::to_string());
	
	return 0;
}

