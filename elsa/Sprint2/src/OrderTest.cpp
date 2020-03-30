#include <iostream>
#include "Desktop.h"
#include "Customer.h"
#include "Order.h"
#include <sstream>
#include <assert.h>

int main()
{
	std::ostringstream test;
	
	Customer customer{"Ahmed", "817-773-7543", "ahmed.malabi@mavs.uta.edu"};
	
	Desktop desktop;
	Options option1{"This is 1", 100.00};
	Options option2{"This is 2", 5.45};
	Options option3{"This is 3", 20.45};
	desktop.add_option(option1);
	desktop.add_option(option2);
	desktop.add_option(option3);
	
	Desktop desktop2;
	Options option4{"This is 1", 100.00};
	Options option5{"This is 2", 5.45};
	Options option6{"This is 3", 20.45};
	desktop2.add_option(option4);
	desktop2.add_option(option5);
	desktop2.add_option(option6);
	
	Order order{customer};

	order.add_product(desktop);
	order.add_product(desktop2);
	std::cout << order;
	
	//assert(test.str() == "Ahmed, 817-773-7543, ahmed.malabi@mavs.uta.edu");
	//assert(deskTest.str() == "This is 1: $100.00 This is 2: $5.45 This is 3: $20.45");
	//assert(desktop.Desktop::price() == 125.90);
	
	return 0;
}
