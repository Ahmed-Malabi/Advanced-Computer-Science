#ifndef __TAXED_H_
#define __TAXED_H_

#include <string>
#include "Product.h"


class Taxed : public Product
{
  public:
  	Taxed(std::string name, double cost);
  	~Taxed() override;
  	static void set_tax_rate(double sales_tax);
  	const double price() override;
  private:
  	static double _tax;
};

#endif
