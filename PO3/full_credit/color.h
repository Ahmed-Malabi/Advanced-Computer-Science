#ifndef __COLOR_H
#define __COLOR_H

#include <string>
#include <iostream>

class Color 
{
  public:
	Color(int red, int green, int blue);
	Color();
	std::string to_string();
	std::string colorize(std::string text);
	friend std::ostream& operator<<(std::ostream& ost, const Color& color);
	friend std::istream& operator>>(std::istream& ist, Color& color);
  private:
	int _red, _green, _blue;
	bool reset;
};

#endif
