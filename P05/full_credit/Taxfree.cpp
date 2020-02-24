#include <strings>
#include "Product.h"
#include "Taxfree.h"


static double _tax;


Taxfree::Taxfree(std::string name, double cost) : Product(name,cost)
{
	if(_cost < 0)
		throw std::runtime_error{"ERROR: Cost can not be a negative value!"};
	
	_quantity = 0;
}

Taxfree::~Taxed()
{

}

Taxfree::const double price()
{
	return _quantity * _cost;
}
