#ifndef __ITEM_H_
#define __ITEM_H_

#include <string>
#include <iostream>

class Item
{
  public:
  	Item(std::string name, double cost);
  	double cost();
  	friend std::ostream& operator<< (std::ostream& ost, const Item item);
  	friend std::istream& operator>> (std::istream& ist, Item& item);
  private:
  	std::string _name;
  	double _cost;
};

#endif
