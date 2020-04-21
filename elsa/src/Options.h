#ifndef __OPTIONS_H_
#define __OPTIONS_H_

#include <string>

class Options
{
  public:
  	Options(std::string name, double cost);
  	Options(std::istream& ist);
  	~Options();
  	double cost();
  	virtual std::string to_string() const;
  	virtual void save(std::ostream& ost);
  	friend std::ostream& operator<<(std::ostream& ost, const Options& option);
  protected:
  	std::string _name;
  	double _cost;
};

#endif
