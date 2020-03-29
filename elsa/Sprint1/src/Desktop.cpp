#include "Desktop.h"
#include "iomanip"

void Desktop::add_option(Options& option)
{
	options.push_back(&option);
}

double Desktop::price() const
{
	double total = 0;
	
	for(int i = 0; i < options.size(); i++)
	{
		total += options.at(i)->Options::cost();
	}
	
	return total;
}

std::ostream& operator<<(std::ostream& ost, const Desktop desktop)
{
	for(int i = 0; i < desktop.options.size(); i++)
	{
		ost << *desktop.options.at(i) << " ";
	}
	
	return ost << std::fixed << std::setprecision(2) << "($" << desktop.Desktop::price() << " )";
}
