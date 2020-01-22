#include <iostream>
#include <string>

int main()
{
	std::string name;
	std::cout << "Please enter your name: ";
	std::getline(std::cin, name) >> name;
	std::cout << "Hello, " << name << "!" << std::endl;
}
