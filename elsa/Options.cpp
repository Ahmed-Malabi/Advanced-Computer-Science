#include "Options.h"
#include <iomanip>
#include <sstream>

Options::Options(std::string name, double cost) : _name{name}, _cost{cost} {}

Options::~Options() {}

double Options::cost()
{
	return _cost;
}

std::string Options::to_string() const
{
	std::ostringstream temp;
	temp << std::fixed << std::setprecision(2) << _cost;
	return _name + ": " + temp.str();
}

std::ostream& operator<<(std::ostream& ost, const Options option)
{
	return ost << option.Options::to_string();
}
