#include "Desktop.h"
#include "iomanip"

Desktop::Desktop() {}

Desktop::Desktop(std::istream& ist)
{
	int size;
	ist >> size;
	ist.ignore(32767,'\n');
	for(int i = 0; i < size; i++)
	{
		options.push_back(new Options{ist});
	}
}

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

void Desktop::save(std::ostream& ost)
{
	ost << options.size() << std::endl;
	for(int i = 0; i < options.size(); i++)
	{
		options.at(i)->save(ost);
	}
}
