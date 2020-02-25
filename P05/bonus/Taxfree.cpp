#include <string>
#include "Product.h"
#include "Taxfree.h"

Taxfree::Taxfree(std::string name, double cost) : Product(name,cost)
{
	if(_cost < 0)
		throw std::runtime_error{"ERROR: Cost can not be a negative value!"};
	
	_quantity = 0;
}

Taxfree::~Taxfree()
{

}

const double Taxfree::price()
{
	return _quantity * _cost;
}
