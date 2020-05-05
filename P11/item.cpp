#include "item.h"
#include <iomanip>

Item::Item(std::string name, double cost) : _name{name}, _cost{cost} {}

double Item::cost()
{
	return _cost;
}

std::ostream& operator<< (std::ostream& ost, const Item item)
{
	return ost << "$ " << std::setprecision(2) << std::fixed << item._cost << " " << item._name;
}

std::istream& operator>> (std::istream& ist, Item& item)
{
	std::string line;
	std::getline(ist,line);
	std::size_t found = line.find_last_of(" ");
	
	try{
		if(!std::stod(line.substr(found+1))) throw line.substr(found+1);
		item._cost = std::stod(line.substr(found+1));
	} catch (std::exception e){
		std::cerr << "Invalid input for cost: " << e.what() << std::endl;
	}
	
	item._name = line.substr(0, found);
}
