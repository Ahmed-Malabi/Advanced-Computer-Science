#ifndef __DESKTOP_H_
#define __DESKTOP_H_

#include "Options.h"
#include "Ram.h"
#include <vector>

class Desktop
{
  public:
  	Desktop();
  	Desktop(std::istream& ist);
  	void add_option(Options& option);
  	double price() const;
  	void save(std::ostream& ost);
  	friend std::ostream& operator<<(std::ostream& ost, const Desktop desktop);
  private:
  	std::vector<Options*> options;
};

#endif
