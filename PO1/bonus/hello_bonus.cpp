#include <iostream>
#include <string>

int main()
{
	std::string name;
	std::cout << "Please enter your name: ";
	std::getline(std::cin, name);
	std::cout << "Hello, " << name << "!" << std::endl;
	return 0;
}
