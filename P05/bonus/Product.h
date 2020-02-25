#ifndef __PRODUCT_H_
#define __PRODUCT_H_

#include <string>
#include <ostream>

class Product
{
  public:
	Product(std::string name, double cost);
	virtual ~Product();
	void set_quantity(int amount);
	virtual const double price();
	friend std::ostream& operator<<(std::ostream& ost, const Product product);
  protected:
	int _quantity;
	double _cost;
	std::string _name;
};

#endif
