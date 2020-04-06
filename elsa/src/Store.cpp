#include "Store.h"

Store::Store() {}

Store::Store(std::istream& ist)
{
	int size;
	ist >> size;
	ist.ignore(32767,'\n');
	for(int i = 0; i < size; i++)
	{
		Customer customer{ist};
		customers.push_back(customer);
	}
	if(!ist.good() && !ist.eof()) throw std::runtime_error{"Error reading file"};
}

void Store::add_customer(Customer& customer)
{
	customers.push_back(customer);
}

int Store::num_customers()
{
	return customers.size();
}

Customer& Store::customer(int index)
{
	return customers.at(index);
}

void Store::add_option(Options& option)
{
	options.push_back(new Options{option});
}

int Store::num_options()
{
	return options.size();
}

Options& Store::option(int index)
{
	return *options.at(index);
}

int Store::new_desktop()
{
	Desktop desktop;
	desktops.push_back(desktop);
	return desktops.size()-1;
}

void Store::add_option(int option, int desktop)
{
	desktops.at(desktop).Desktop::add_option(*options.at(option));
}

void Store::save(std::ostream& ost)
{
	ost << customers.size() <<std::endl;
	for(int i = 0; i < customers.size(); i++){customers.at(i).save(ost);}
	if(!ost.good() && !ost.eof()) throw std::runtime_error{"Error writing file"};
}

int Store::num_desktops()
{
	return desktops.size();
}

Desktop& Store::desktop(int index)
{
	return desktops.at(index);
}

int Store::new_order(int customer)
{
	Order order{customers.at(customer)};
	orders.push_back(order);
	return orders.size()-1;
}

void Store::add_desktop(int desktop, int order)
{
	orders.at(order).Order::add_product(desktops.at(desktop));
}

int Store::num_orders()
{
	return orders.size();
}

Order& Store::order(int index)
{
	return orders.at(index);
}
