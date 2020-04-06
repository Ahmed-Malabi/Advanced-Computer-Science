#include "Customer.h"

Customer::Customer(std::string name, std::string phone, std::string email) : _name{name}, _phone{phone}, _email{email} {}

std::ostream& operator<<(std::ostream& ost, const Customer customer)
{
	return ost << customer._name << ", " << customer._phone << ", " << customer._email;
}

Customer::Customer(std::istream& ist)
{

}

void Customer::save(std::ostream& ost)
{

}


