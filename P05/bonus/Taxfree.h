#ifndef __TAXFREE_H_
#define __TAXFREE_H_

#include <string>
#include "Product.h"


class Taxfree : public Product
{
  public:
  	Taxfree(std::string name, double cost);
  	~Taxfree() override;
  	const double price() override;
};

#endif
