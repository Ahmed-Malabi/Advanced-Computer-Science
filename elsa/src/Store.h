#ifndef __STORE_H_
#define __STORE_H_

#include "Order.h"

class Store
{
  public:
  	Store();
  	Store(std::istream& ist);
  	void add_customer(Customer& customer);
  	int num_customers();
  	Customer& customer(int index);
  	void add_option(Options& option);
  	int num_options();
  	Options& option(int index);
  	int new_desktop();
  	void add_option(int option, int desktop);
  	int num_desktops();
  	Desktop& desktop(int index);
  	int new_order(int customer);
  	void add_desktop(int desktop, int order);
  	int num_orders();
  	Order& order(int index);
  	void save(std::ostream& ost);
  private:
  	std::vector<Customer> customers;
  	std::vector<Options*> options;
  	std::vector<Desktop> desktops;
  	std::vector<Order> orders;
};

#endif
