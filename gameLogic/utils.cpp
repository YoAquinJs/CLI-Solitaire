#include <iostream>
#include "utils.hpp"

void PrintLine(std::string text){
	std::cout << text << std::endl;
}

void ColorPrint(std::string text, std::string color){
	std::cout << color << text << RESET << std::endl;
}