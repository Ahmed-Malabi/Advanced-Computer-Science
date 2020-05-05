#ifndef __CART_H_
#define __CART_H_

#include <string>
#include <vector>
#include "item.h"

class Cart
{
  private:
    typedef std::vector<Item*> Items;
  	std::string _customer;
  	Items _items;
  public:
  	Cart(std::string customer);
  	~Cart();
  	Cart(const Cart& cart);
  	Cart& operator= (const Cart& cart);
  	void add_item(Item& item);
  	double cost();
  	typedef Items::iterator iterator;
  	typedef Items::const_iterator const_iterator;
  	iterator begin() {return _items.begin();}
  	iterator end() {return _items.end();}
};

#endif
