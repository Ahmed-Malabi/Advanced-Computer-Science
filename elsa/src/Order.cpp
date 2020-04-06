#include "Order.h"
#include <iomanip>

Order::Order(Customer& customer) : _customer{customer} {}

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

	ost << order._customer <<" is buying ";
	
	for(int i = 0; i< order._products.size(); i++)
	{
		ost << *order._products.at(i) << " ";
	}
	
	ost << std::fixed << std::setprecision(2) << "total: " << order.Order::price() <<std::endl;
}

void Order::save(std::ostream& ost)
{

}
