#ifndef __COIN_H
#define __COIN_H

#include <string>
#include <ostream>

typedef year int;

enum class Coin_size
{
	PENNY = 1,
	NICKEL = 5,
	DIME = 10,
	QUARTER = 25;
}

class Coin
{
  public:
  	Coin(Coin::Coin_size Size, year Year);
  	Coin(const Coin& rhs);
  	Coin& operator=(const Coin& rhs);
  	~Coin();
  	void add_note(string s);
  	friend ostream& operator<< (ostream& ost, const Coint& coin);
  private:
	Coin_size _size;
	year _year;
	string* _notes;
}

#endif
