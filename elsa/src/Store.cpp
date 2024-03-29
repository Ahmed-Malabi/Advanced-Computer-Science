#include "Store.h"

Store::Store() {}

Store::Store(std::istream& ist)
{
	int size;
	std::string str;
	if(ist >> size)
	{
		ist.ignore(32767,'\n');
		for(int i = 0; i < size; i++)
		{
			customers.push_back(Customer{ist});
			if(ist.eof())
				return;
		}
		size = 0;
	}
	if(ist >> size)
	{
		ist.ignore(32767,'\n');
		for(int i = 0; i < size; i++)
		{
			ist >> str;
			if(str == "generic")
				options.push_back(new Options{ist});
			else
				options.push_back(new Ram{ist});
			if(ist.eof())
				return;
			str = "";
		}
		size = 0;
	}
	
	if(ist >> size)
	{
		ist.ignore(32767,'\n');
		for(int i = 0; i < size; i++)
		{
			Desktop desktop{ist};
			desktops.push_back(desktop);
			if(ist.eof())
				return;
		}
		size = 0;
	}
	
	if(ist >> size)
	{
		ist.ignore(32767,'\n');
		for(int i = 0; i < size; i++)
		{
			Order order{ist};
			orders.push_back(order);
			if(ist.eof())
				return;
		}
		size = 0;
	}
	
	if(ist.fail() || ist.bad()) throw std::runtime_error{"Error reading file"};
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
	options.push_back(&option);
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
	ost << customers.size() << std::endl;
	for(int i = 0; i < customers.size(); i++){customers.at(i).save(ost);}
	
	ost << options.size() << std::endl;
	for(int i = 0; i < options.size(); i++){options.at(i)->save(ost);}
	
	ost << desktops.size() << std::endl;
	for(int i = 0; i < desktops.size(); i++){desktops.at(i).save(ost);}
	
	ost << orders.size() << std::endl;
	for(int i = 0; i < orders.size(); i++){orders.at(i).save(ost);}
	
	if(ost.fail() || ost.bad()) throw std::runtime_error{"Error writing file"};
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
