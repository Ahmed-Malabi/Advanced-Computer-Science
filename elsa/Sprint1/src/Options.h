#ifndef __OPTIONS_H_
#define __OPTIONS_H_

#include <string>

class Options
{
  public:
  	Options(std::string name, double cost);
  	~Options();
  	double cost();
  	std::string to_string() const;
  	friend std::ostream& operator<<(std::ostream& ost, const Options option);
  protected:
  	std::string _name;
  	double _cost;
};

#endif
