#ifndef __COIN_H
#define __COIN_H

#include <string>
#include <iostream>

typedef int Year;

enum class Coin_size
{
	PENNY = 1,
	NICKEL = 5,
	DIME = 10,
	QUARTER = 25
};

class Coin
{
  public:
  	Coin(Coin_size Size, Year Year);
  	Coin(const Coin& rhs);
  	Coin& operator=(const Coin& rhs);
  	~Coin();
  	void add_note(std::string s);
  	friend std::ostream& operator<< (std::ostream& ost, const Coin& coin);
  private:
	Coin_size _size;
	Year _year;
	std::string* _notes;
};

#endif
