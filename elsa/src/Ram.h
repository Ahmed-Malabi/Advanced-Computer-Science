#ifndef __RAM_H_
#define __RAM_H_

#include "Options.h"

class Ram : public Options
{
  public:
  	Ram(std::string name, double cost, int gb);
  	Ram(std::istream& ist);
  	~Ram();
	std::string to_string() const override;
	void save(std::ostream& ost) override;
  protected:
  	int _gb;
};

#endif
