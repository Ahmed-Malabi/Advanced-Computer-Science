#include "cart.h"

Cart::Cart(std::string customer) : _customer{customer} {}

Cart::~Cart()
{
	for(Item* i : _items) delete i;
}

Cart::Cart(const Cart& cart)
{
	_customer = cart._customer;
	for(Item* i : cart._items) _items.push_back(new Item{*i});
}

Cart& Cart::operator= (const Cart& cart)
{
	Cart* temp = new Cart{cart._customer};
	if(temp == &cart) return *temp;

	for(Item* i : cart._items) temp->_items.push_back(new Item(*i));
	return *temp;
}

void Cart::add_item(Item& item)
{
	_items.push_back(new Item(item));
}

double Cart::cost()
{
	double cost;
	for(Item* i : _items) cost += i->cost();
	return cost;
}
