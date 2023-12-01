#include <string>
#include <iostream>

#include "gameLogic.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

void ColorPrint(std::string text, std::string color){
	std::cout << color << text << RESET << "\n";
}

void Render(Game* gameObj){
	ColorPrint("--------------------------Solitarie--------------------------", GREEN);
	std::cout << " Press Space to Start\n";
}