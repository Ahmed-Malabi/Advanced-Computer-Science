#include "coin.h"
#include <ostream>
#include <string>


Coin(Coin::Coin_size Size, year Year) : _size{Size}, _year{}
{
	if(_size == Coin_size::PENNY && _year < 1793)
		throw "ERROR: that penny can not physically exist!";
		
	else if(_size == Coin_size::NICKEL && _year < 1866)
		throw "ERROR: that nickel can not physically exist!";
		
	else if(_size == Coin_size::DIME && _year < 1946)
		throw "ERROR: that dime can not physically exist!";
		
	else if(_size == Coin_size::QUARTER && _year < 1796)
		throw "ERROR: that quarter can not physically exist!";
		
	else
	{
		if(_size != Coin_size::PENNY && _size != Coin_size::NICKEL && _size != Coin_size::DIME && _size != Coin_size::QUARTER)
			throw "ERROR: that coin does not exist"
	}
	_note = nullptr;
	LOG("Coin::Coin(" + _size + "," + _year + ")");
}

Coin(const Coin& rhs) : _size{rhs._size}, _year{rhs._year}
{
	_note = new string*(rhs._note);
}

Coin& operator=(const Coin& rhs)
{
	_size = rhs._size;
	_year = rhs._year;
	_note = new string*(rhs._note);
}

~Coin()
{
	delete _note;
	LOG("Coin::~Coin");
}

void add_note(string s)
{
	if(!_notes)
	{
		_notes = new string*(s);
	}
	else
	{
		_notes.append(" ");
		_notes.append(s);
	}
}

ostream& operator<< (ostream& ost, const Coin& coin)
{
	if(coin._size == Coin_size::PENNY)
		ost << coin._year << " penny\n" << coin._note << std::endl;
		
	else if(coin._size == Coin_size::NICKEL)
		ost << coin._year << " nickel\n" << coin._note << std::endl;
		
	else if(coin._size == Coin_size::DIME)
		ost << coin._year << " dime\n" << coin._note << std::endl;
		
	else
		ost << coin._year << " quarter\n" << coin._note << std::endl;
	
	return ost;
}
