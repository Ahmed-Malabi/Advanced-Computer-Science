#include <iostream>
#include <string>

int main()
{
	std::string name;
	name = getenv("USER");
	std::cout << "Hello, " << name << "!" << std::endl;
}
