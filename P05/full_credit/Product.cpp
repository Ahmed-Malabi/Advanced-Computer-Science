#include <string>
#include <ostream>
#include "Product.h"


Product::Product(std::string name, double cost) : _name{name}, cost{cost}
{
	if(_cost < 0)
		throw std::runtime_error{"ERROR: Cost can not be a negative value!"};
	
	_quantity = 0;
}

Product::~Product()
{

}

Product::void set_quantity(int amount)
{
	_name = amount;
}

Product::const double price()
{
	return _quantity * _cost * (1+_tax);
}

std::ostream& operator<<(std::ostream& ost, const Product product)
{
	ost << std:setprecision(2) << product._name << '(' << if(product._quantity > 0){product._quantity << ' '} << '@' <<  product._cost;
	return ost;
}
