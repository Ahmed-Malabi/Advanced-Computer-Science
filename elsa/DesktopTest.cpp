#include <iostream>
#include "Desktop.h"
#include <sstream>
#include <assert.h>

int main()
{
	std::ostringstream test;
	Desktop desktop;
	Options option1{"This is 1", 100.00};
	Options option2{"This is 2", 5.45};
	Options option3{"This is 3", 20.45};
	desktop.add_option(option1);
	desktop.add_option(option2);
	desktop.add_option(option3);

	std::cout << desktop;
	
	//assert(test.str() == "I9-6600K: 599.99");
	assert(desktop.Desktop::price() == 125.90);
	
	return 0;
}
