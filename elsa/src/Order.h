#ifndef __ORDER_H_
#define __ORDER_H_

#include "Customer.h"
#include "Desktop.h"

class Order
{
  public:
  	Order(Customer& customer);
  	Order(std::istream& ist);
  	~Order();
  	int add_product(Desktop& desktop);
  	double price() const;
  	void save(std::ostream& ost);
  	friend std::ostream& operator<<(std::ostream& ost, const Order order);
  private:
  	Customer* _customer;
  	std::vector<Desktop*> _products;
};

#endif
