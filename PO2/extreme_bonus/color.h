#ifndef __COLOR_H
#define __COLOR_H

#include <string>
#include <vector>

class Color 
{
  public:
	Color(int red, int green, int blue);
	std::string to_string();
	std::string colorize(std::string text);
	int magnitude();
	void compare(std::vector<Color>& vec);
  private:
	int _red, _green, _blue;
};

#endif
