#include <iostream>
#include "Options.h"
#include <sstream>
#include <assert.h>

int main()
{
	std::ostringstream test;
	Options option{"I9-6600K", 599.99};

	test << option;
	
	assert(test.str() == "I9-6600K: 599.99");
	assert(option.cost() == 599.99);
	assert(option.Options::to_string() == "I9-6600K: 599.99");
	
	return 0;
}
