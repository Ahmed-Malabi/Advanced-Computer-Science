#include "Options.h"
#include <iomanip>
#include <sstream>

Options::Options(std::string name, double cost) : _name{name}, _cost{cost} {}

Options::Options(std::istream& ist)
{
	getline(ist, _name);
	std::string cost;
	getline(ist, cost);
	_cost = std::stod(cost);
}

Options::~Options() {}

double Options::cost()
{
	return _cost;
}

std::string Options::to_string() const
{
	std::ostringstream temp;
	temp << std::fixed << std::setprecision(2) << _cost;
	return _name + ": $" + temp.str();
}

std::ostream& operator<<(std::ostream& ost, const Options option)
{
	return ost << option.Options::to_string();
}

void Options::save(std::ostream& ost)
{
	ost << _name << std::endl;
	ost << _cost << std::endl;
}
