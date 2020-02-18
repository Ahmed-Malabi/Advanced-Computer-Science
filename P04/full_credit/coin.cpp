#include "coin.h"
#include "logger.h"
#include <iostream>
#include <string>


Coin::Coin(Coin_size Size, Year Year) : _size{Size}, _year{Year}
{
	if(_size == Coin_size::PENNY && _year < 1793)
		throw std::runtime_error{"ERROR: that penny can not physically exist!"};
		
	else if(_size == Coin_size::NICKEL && _year < 1866)
		throw std::runtime_error{"ERROR: that nickel can not physically exist!"};
		
	else if(_size == Coin_size::DIME && _year < 1946)
		throw std::runtime_error{"ERROR: that dime can not physically exist!"};
		
	else if(_size == Coin_size::QUARTER && _year < 1796)
		throw std::runtime_error{"ERROR: that quarter can not physically exist!"};
		
	else
	{
		if(_size != Coin_size::PENNY && _size != Coin_size::NICKEL && _size != Coin_size::DIME && _size != Coin_size::QUARTER)
			throw std::runtime_error{"ERROR: that kind of coin does not exist"};
	}
	this->_notes = nullptr;
	LOG("Coin::Coin");
}

Coin::Coin(const Coin& rhs) : _size{rhs._size}, _year{rhs._year}, _notes(new std::string(*rhs._notes))
{
	LOG("Coin::Coin Copy constructor");
}

Coin& Coin::operator=(const Coin& rhs)
{
	this->_size = rhs._size;
	this->_year = rhs._year;
	this->_notes = new std::string(*rhs._notes);
	LOG("Coin::Coin Copy operator=");
	
	return *this;
}

Coin::~Coin()
{
	delete this->_notes;
	LOG("Coin::~Coin");
}

void Coin::add_note(std::string s)
{
	if(!this->_notes)
	{
		this->Coin::_notes = new std::string(s);
	}
	else
	{
		this->Coin::_notes->append(" ");
		this->Coin::_notes->append(s);
	}
}

std::ostream& operator<< (std::ostream& ost, const Coin& coin)
{
	if(coin._size == Coin_size::PENNY)
		ost << coin._year << " penny\n" << *coin._notes << std::endl;
		
	else if(coin._size == Coin_size::NICKEL)
		ost << coin._year << " nickel\n" << *coin._notes << std::endl;
		
	else if(coin._size == Coin_size::DIME)
		ost << coin._year << " dime\n" << *coin._notes << std::endl;
		
	else
		ost << coin._year << " quarter\n" << *coin._notes << std::endl;
	
	return ost;
}
