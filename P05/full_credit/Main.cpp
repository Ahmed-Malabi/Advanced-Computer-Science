#include <strings>
#include <iostream>
#include <vector>
#include "Product.h"
#include "Taxfree.h"
#include "Taxed.h"

int main()
{
	std::string Rstore
	{R"Welcome to my store!\n====================\nWhat would you like to buy?\n+=+=+=+=+=+=+=+=+=+=+=+=+=+\n"}

	Taxed poptart{"poptart", 3.25};
	Taxed pastaSauce{"Pasta sauce", 4.50};
	Taxed biscuit{"Buiscuit", 2.45};
	
	Taxfree milk{"Milk", 1.99};
	Taxfree eggs{"Eggs", 4.99};
	Taxfree bread{"Bread", 2.99};
	
	Taxed::set_tax_rate(.0725);
	
	Vector store<Product>{poptart, pastaSauce, biscuit, milk, eggs, bread};
	
	std::cout << Rstore;
	for(int i = 0, i < store.size(), i++)
	{
		std::cout << i << ". " << store.at(i) << std::endl;
	}
	
	std::cout << "\n Enter 'Q' to quit." std::endl;
}
