#include <string>
#include "Product.h"
#include "Taxed.h"


double Taxed::_tax;


Taxed::Taxed(std::string name, double cost) : Product(name,cost)
{
	if(_cost < 0)
		throw std::runtime_error{"ERROR: Cost can not be a negative value!"};
	
	_quantity = 0;
}

Taxed::~Taxed()
{

}

void Taxed::set_tax_rate(double sales_tax)
{
	Taxed::_tax = sales_tax;
}

const double Taxed::price()
{
	return _quantity * _cost * (1+_tax);
}
