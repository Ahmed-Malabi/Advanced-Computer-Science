#include <iostream>
#include "Desktop.h"
#include "Customer.h"
#include "Order.h"
#include "Store.h"
#include <sstream>
#include <assert.h>

int main()
{
	std::ostringstream test;
	Store store;
	Customer customer{"Ahmed", "817-773-7543", "ahmed.malabi@mavs.uta.edu"};
	store.add_customer(customer);
	std::cout << store.Store::num_customer() << std::endl;
	std::cout << store.Store::customer(0) << std::endl;
	
	Options option1{"This is 1", 100.00};
	Options option2{"This is 2", 5.45};
	Options option3{"This is 3", 20.45};
	
	store.Store::add_option(option1);
	store.Store::add_option(option2);
	store.Store::add_option(option3);
	
	std::cout << store.Store::num_options() << std::endl;
	
	Options option4{"This is 1", 100.00};
	Options option5{"This is 2", 5.45};
	Options option6{"This is 3", 20.45};
	
	store.Store::add_option(option4);
	store.Store::add_option(option5);
	store.Store::add_option(option6);
	
	std::cout << store.Store::num_options() << std::endl;
	std::cout << store.option(0) << std::endl;
	
	store.Store::new_desktop();
	store.Store::add_option(0, 0);
	store.Store::add_option(1, 0);
	store.Store::add_option(2, 0);
	
	store.Store::new_desktop();
	store.Store::add_option(3, 1);
	store.Store::add_option(4, 1);
	store.Store::add_option(5, 1);
	
	std::cout << store.num_desktops() << std::endl;
	std::cout << store.desktop(0);
	
	store.Store::new_order(0);
	store.Store::add_desktop(0,0);
	
	store.Store::new_order(0);
	store.Store::add_desktop(0,1);
	
	std::cout << store.Store::num_orders() << std::endl;
	
	std::cout << store.Store::order(0) << std::endl;

	
	//assert(test.str() == "Ahmed, 817-773-7543, ahmed.malabi@mavs.uta.edu");
	//assert(deskTest.str() == "This is 1: $100.00 This is 2: $5.45 This is 3: $20.45");
	//assert(desktop.Desktop::price() == 125.90);
	
	return 0;
}
