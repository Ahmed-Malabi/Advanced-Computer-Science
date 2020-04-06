#include "Order.h"
#include <iomanip>

Order::Order(Customer& customer) : _customer{&customer} {}

Order::Order(std::istream& ist)
{
	_customer = new Customer(ist);
	int size;
	ist >> size;
	ist.ignore(32767,'\n');
	for(int i = 0; i < size; i++)
	{
		_products.push_back(new Desktop{ist});
	}
}

Order::~Order() {}

int Order::add_product(Desktop& desktop)
{
	Desktop* temp = new Desktop;
	*temp = desktop;
	_products.push_back(temp);
	return _products.size()-1;
}

double Order::price() const
{
	double total;
	for(int i = 0; i < _products.size(); i++)
	{
		total += _products.at(i)->Desktop::price();
	}
	
	return total;
}

std::ostream& operator<<(std::ostream& ost, const Order order)
{

	ost << *(order._customer) <<" is buying:\n";
	
	for(int i = 0; i< order._products.size(); i++)
	{
		ost << *order._products.at(i) << "\n";
	}
	
	ost << std::fixed << std::setprecision(2) << "\ntotal: " << order.Order::price() <<std::endl;
}

void Order::save(std::ostream& ost)
{
	_customer->save(ost);
	
	for(int i = 0; i < _products.size(); i++)
	{
		_products.at(i)->save(ost);
	}
}
