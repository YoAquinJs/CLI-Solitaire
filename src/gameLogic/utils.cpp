#include <string>
#include <iostream>

#include "utils.hpp"

int StringColorExcludingLength(const std::string& str){
	int count = str.length();
	for (std::string colorStr : COLORS) {
		int pos = 0;
		int finds = 0;

		while ((pos = str.find(colorStr, pos)) != std::string::npos) {
			finds++;
			pos += colorStr.length();
		}
		count-=(finds*colorStr.length());
	}

	return count;
}

void PrintLine(const std::string& text, bool endLine){
	std::string emptySpace((windowWidth-StringColorExcludingLength(text))/2, ' ');
	std::cout << emptySpace << text << emptySpace << (endLine ? "\n" : "");
}

void ColorPrint(const std::string& text, const std::string& color, bool endLine){
	std::cout << color;
	PrintLine(text, endLine);
	std::cout << RESET;
}
