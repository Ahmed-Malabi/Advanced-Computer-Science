#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Product.h"
#include "Taxfree.h"
#include "Taxed.h"

int main()
{
	Taxed poptart{"poptart", 3.25};
	Taxed pastaSauce{"Pasta sauce", 4.51};
	Taxed biscuit{"Buiscuit", 2.45};
	
	Taxfree milk{"Milk", 1.99};
	Taxfree eggs{"Eggs", 4.99};
	Taxfree bread{"Bread", 2.99};
	
	Taxed::set_tax_rate(.0725);
	
	std::vector<Taxed> taxed{poptart, pastaSauce, biscuit};
	std::vector<Taxfree> taxfree{milk, eggs, bread};
	std::vector<Taxed> ct{};
	std::vector<Taxfree> ctf{};
	
	int linenum;
	int amount;
	double total;
	
	while(true)
	{
		std::cout << "Welcome to my store!\n====================\nWhat would you like to buy?\n+=+=+=+=+=+=+=+=+=+=+=+=+=+\n";
		for(int i = 0; i < taxed.size() + taxfree.size(); i++)
		{
			if(i<3)
				std::cout << i << ". " << taxed.at(i) << std::endl;
			else
				std::cout << i << ". " << taxfree.at(i-3) << std::endl;
		}
		
		std::cout << "\n Enter row num and quantity (0 to quit)" << std::endl;
		
		
		
		std::cout << "What would you like to buy? (enter line number followed by ammount)" << std::endl;
		std::cin >> linenum >> amount;
		
		if(linenum < 0)
			throw std::runtime_error{"ERROR: Amount can not be a negative value!"};
		else if(amount ==0)
			break;
		else if(linenum < 3)
		{
			ct.push_back(taxed.at(linenum));
			ct.back().Product::set_quantity(amount);
			total += ct.back().Taxed::price();
		}
		else
		{
			ctf.push_back(taxfree.at(linenum-3));
			ctf.back().Product::set_quantity(amount);
			total += ctf.back().Taxfree::price();
		}
		
		std::cout << "\n\nCurrent Cart\n------------" << std::endl;
		for(int i = 0; i < ct.size(); i++)
		{
				std::cout << ct.at(i) << std::endl;
		}
		for(int i = 0; i < ctf.size(); i++)
		{
				std::cout << ctf.at(i) << std::endl;
		}
		std::cout << "\nTotal price: " << std::setprecision(3) << total << "\n\n";
	}
}
