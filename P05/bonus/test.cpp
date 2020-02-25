#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <assert.h> 
#include "Product.h"
#include "Taxfree.h"
#include "Taxed.h"

int main()
{
	std::string test;
	Taxfree tfTest{"milk", 2.45};
	tfTest.Product::set_quantity(-1);
	test << tfTest;
	assert(test == "milk ($2.45)");
	assert(tfTest.Taxfree::price() == -2.45)
	
	Taxed taxedTest{"egg", 2.25};
	Taxed::set_tax_rate(0.0725);
	test << taxedTest;
	assert(test == "egg ($2.25)");
	assert(taxedTest.Taxed::price() == -2.41)
}
