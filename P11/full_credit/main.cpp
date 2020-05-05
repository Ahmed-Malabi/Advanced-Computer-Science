#include "cart.h"
#include <iostream>
#include <iomanip>
#include <sstream>

int main()
{
	Cart cart{"Ahmed Malabi"};
	Item item{"",0};
	
	std::cout << "Enter the name of the item followed by cost (apples 2.45)" << std::endl;
	while(!std::cin.eof())
	{
		try{	
				std::cin >> item;
				cart.add_item(item);
		} catch (std::exception& e){
			std::cerr << "Invalid input for cost: " << e.what() << std::endl;
		}
	}
	
	std::cout << "Reciept\n" << std::endl;
	for(Item* i : cart) std::cout << *i << std::endl;
	std::cout << "==========" << "\n" << "$ " << std::setprecision(2) << std::fixed << cart.cost() << "\t total cost" << std::endl;
}
