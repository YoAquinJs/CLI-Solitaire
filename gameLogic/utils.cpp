#include <string>
#include <iostream>

#include "utils.hpp"

int StringColorExcludingLength(std::string str){
	int count = str.length();
	std::string colorStrs[] = {RESET, RED, GREEN, YELLOW, BLUE};
	for (std::string colorStr : colorStrs) {
        int pos = 0;
    	int finds = 0;

    	while ((pos = str.find(colorStr, pos)) != std::string::npos) {
    	    ++finds;
    	    pos += colorStr.length();
    	}
		count-=(finds*colorStr.length());
    }

	return count;
}

void PrintLine(std::string text, bool endLine){
	std::string emptySpace((windowWidth-StringColorExcludingLength(text))/2, ' ');
	std::cout << emptySpace << text << emptySpace << (endLine ? "\n" : "");
}

void ColorPrint(std::string text, std::string color, bool endLine){
	std::cout << color;
	PrintLine(text, endLine);
	std::cout << RESET;
}
