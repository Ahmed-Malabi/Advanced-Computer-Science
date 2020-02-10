#include "color.h"
#include <iostream>
#include <string>



Color::Color()
{
	this.reset = true;
}

Color::Color(int red, int green, int blue) : _red{red}, _green{green}, _blue{blue}
{
	if((red < 0 || red > 255) || (green < 0 || green > 255) || (blue < 0 || blue > 255))
	{
		std::cerr << "One of the values you entered was out of bounds" <<std::endl;
		exit(1);
	}
	
	this.reset = false;
}

std::string Color::to_string()
{
	return "(" + std::to_string(_red) + "," + std::to_string(_green) + "," + std::to_string(_blue) + ")";
}

std::string Color::colorize(std::string text)
{
	return "\033[38;2;" + std::to_string(_red) + ";" + std::to_string(_green) + ";" + std::to_string(_blue) + ";177m " + text + "\033[0m";
}

friend std::ostream& operator<<(ostream& ost, const Color& color)
{
	
}
	
friend std::ostream& operator>>(ostream& ost, const Color& color)
{
	
}
