#include <strings>
#include "Product.h"
#include "Taxed.h"


static double _tax;


Taxed::Taxed(std::string name, double cost) : Product(name,cost)
{
	if(_cost < 0)
		throw std::runtime_error{"ERROR: Cost can not be a negative value!"};
	
	_quantity = 0;
}

Taxed::~Taxed()
{

}

Taxed::static void set_tax_rate(double sales_tax)
{
	_tax = sales_tax;
}

Taxed::const double price()
{

}
