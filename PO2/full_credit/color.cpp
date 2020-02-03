#include "color.h"
#include <iostream>
#include <string>



Color::Color(int red, int green, int blue) _red{red}, _green{green}, _blue{blue}
{
	int _red, _green, _blue;
	if((red < 0 || red > 255) || (green < 0 || green > 255) || (blue < 0 || blue > 255))
	{
		std::cerr << "One of the values you entered was out of bounds" <<endl;
		exit();
	}
}

std::String Color::toString()
{
	return cout << "(" + std::toString(_red) + "," + std::toString(_green) + "," + std::toString(_blue) + ")";
}

std::string colorize(std::string text)
{
	return "\033[38;2;" + _red + ";" + _green + ";" + _blue + ";177m " + text + "\033[0m";
}

