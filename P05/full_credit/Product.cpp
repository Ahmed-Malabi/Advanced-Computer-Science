#include <string>
#include <ostream>
#include <iomanip>
#include "Product.h"


Product::Product(std::string name, double cost) : _name{name}, _cost{cost}
{
	if(_cost < 0)
		throw std::runtime_error{"ERROR: Cost can not be a negative value!"};
	
	_quantity = 0;
}

Product::~Product()
{

}

void Product::set_quantity(int amount)
{
	_quantity = amount;
}

const double Product::price()
{

}

std::ostream& operator<<(std::ostream& ost, const Product product)
{
	if(product._quantity > 0)
		ost << std::setprecision(3) << product._name << " (" << product._quantity << " @" << " $" <<  product._cost << ')';
	else
		ost << std::setprecision(3) << product._name << " (" <<  "$" <<  product._cost << ')';
	return ost;
}
