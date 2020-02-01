#include <color.h>
#include <iostream>
#include <string>

class Color 
{
  public:
	Color::Color(int red, int green, int blue) _red(red), _green(green), _blue(blue)
	{
		if((red < 0 || red > 255) || (green < 0 || green > 255) || (blue < 0 || blue > 255))
		{
			
		}
	}
	Color::~Color();
	std::String Color::toString()
	{
		return cout << std::toString(_red) + ";" + std::toString(_green) + ";" + std::toString(_blue);
	}
	std::string colorize(std::string text)
	{
		
	}
  private:
	int _red, _green, _blue;
}
