#include "color.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cctype>



Color::Color()
{
	this->reset = true;
}

Color::Color(int red, int green, int blue) : _red{red}, _green{green}, _blue{blue}
{
	if((red < 0 || red > 255) || (green < 0 || green > 255) || (blue < 0 || blue > 255))
	{
		std::cerr << "One of the values you entered was out of bounds" <<std::endl;
		exit(1);
	}
	
	this->reset = false;
}

std::string Color::to_string()
{
	return "(" + std::to_string(_red) + "," + std::to_string(_green) + "," + std::to_string(_blue) + ")";
}

std::ostream& operator<<(std::ostream& ost, const Color& color)
{
	if(color.reset)
		ost << "\033[38;2;;177m ";
	else
		ost << "\033[38;2;" << std::to_string(color._red) << ";" + std::to_string(color._green) << ";" + std::to_string(color._blue) << ";177m ";
	
	return ost;
}

std::istream& operator>>(std::istream& ist, Color& color)
{

	std::string str;
	std::string delim{","};
	
	ist >> str;
	
	str.erase(std::remove(str.begin(),str.end(),"("),str.end());
	str.erase(std::remove(str.begin(),str.end(),")"),str.end());
	
	std::string token;
	
	token = str.substr(0,str.find(delim));
	color._red = stoi(token);
	str.erase(token.length()+2);
	
	token = str.substr(0,str.find(delim));
	color._green = stoi(token);
	str.erase(token.length()+2);
	
	token = str.substr(0,str.find(delim));
	color._blue = stoi(token);
	str.erase();
	
	
	if((color._red < 0 || color._red > 255) || (color._green < 0 || color._green > 255) || (color._blue < 0 || color._blue > 255))
	{
		std::cerr << "One of the values you entered was out of bounds" <<std::endl;
		exit(1);
	}
	
	return ist;	
}
