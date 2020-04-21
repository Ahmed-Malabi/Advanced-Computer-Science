#include "Ram.h"
#include <iomanip>
#include <sstream>

Ram::Ram(std::string name, double cost, int gb) : Options(name,cost), _gb{gb} {}

Ram::Ram(std::istream& ist): Options(ist)
{
	std::string gb;
	getline(ist, gb);
	_gb = std::stoi(gb);
}

Ram::~Ram() {}

std::string Ram::to_string() const
{
	std::ostringstream temp;
	temp << " " << _gb << " GB: $" << std::fixed << std::setprecision(2) << _cost;
	return _name + temp.str();
}

void Ram::save(std::ostream& ost)
{
	ost << "ram" << std::endl;
	ost << _name << std::endl;
	ost << _cost << std::endl;
	ost << _gb << std::endl;
}
