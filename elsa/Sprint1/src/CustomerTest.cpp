#include <iostream>
#include "Customer.h"
#include <sstream>
#include <assert.h>

int main()
{
	std::ostringstream test;
	Customer customer{"Ahmed", "817-773-7543", "ahmed.malabi@mavs.uta.edu"};

	test << customer;
	assert(test.str() == "Ahmed, 817-773-7543, ahmed.malabi@mavs.uta.edu");
	
	return 0;
}
