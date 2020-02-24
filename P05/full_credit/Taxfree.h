#ifndef __TAXFREE_H_
#define __TAXFREE_H_

#include <strings>
#include "Product.h"


class Taxfree : virtual Product
{
  public:
  	Taxfree(std::string name, double cost);
  	~Taxfree() override;
  	const double price() override;
}

#endif
