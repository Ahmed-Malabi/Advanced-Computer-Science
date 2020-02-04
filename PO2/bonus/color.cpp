#include "color.h"
#include <iostream>
#include <string>



Color::Color(int red, int green, int blue) : _red{red}, _green{green}, _blue{blue}
{
	if((red < 0 || red > 255) || (green < 0 || green > 255) || (blue < 0 || blue > 255))
	{
		std::cerr << "One of the values you entered was out of bounds" <<std::endl;
		exit(1);
	}
}

std::string Color::to_string()
{
	return "(" + std::to_string(_red) + "," + std::to_string(_green) + "," + std::to_string(_blue) + ":" + std::to_string(magnitude()) + ")\n";
}

std::string Color::colorize(std::string text)
{
	return "\033[38;2;" + std::to_string(_red) + ";" + std::to_string(_green) + ";" + std::to_string(_blue) + ";177m " + text + "\033[0m";
}

int Color::magnitude()
{
	return ((((float)_red/255)*21)*2.55) + ((((float)_green/255)*71)*2.55) + ((((float)_blue/255)*8)*2.55);
}

int Color::compare(const Color& rhs)
{
	
}
