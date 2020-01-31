#ifndef __COLOR_H
#define __COLOR_H

#include <string>

class Color 
{
  public:
	Color(int r, int b, int g);
	~Color();
	std::string toString();
	std::string colorize(std::string text);
  private:
	int r, g, b;
};

#endif
