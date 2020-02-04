#include "color.h"
#include <iostream>
#include <string>
#include <vector>

int main()
{	
	Color col_1{100,100,100};
	Color col_2(180,200,90);
	Color col_3(255,255,255);
	Color col_4(123,200,255);
	Color col_5(100,100,100);
	
	std::vector<Color> vector;
	
	vector.push_back(col_3);
	vector.push_back(col_1);
	vector.push_back(col_5);
	vector.push_back(col_4);
	vector.push_back(col_2);
	
	for(int i = 0; i < vector.size(); i++)
		std::cout << vector[i].Color::colorize(vector[i].Color::to_string()) << " ";
	std::cout << std::endl;
	
	col_1.Color::compare(vector);
	
	for(int i = 0; i < vector.size(); i++)
		std::cout << vector[i].Color::colorize(vector[i].Color::to_string()) << " ";
	std::cout << std::endl;
	return 0;
}

