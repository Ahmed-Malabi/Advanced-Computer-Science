#ifndef __COLOR_H
#define __COLOR_H

#include <cstring>

Class Color 
{
  public:
	Color(int r, int b, int g);
	~Color;
	std::String toString();
	std::string colorize(std::string text);
  private:
	int r, g, b;
};

#endif
