#pragma once

#include <iostream>
#include "../classes/card.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

void PrintLine(std::string text);
void ColorPrint(std::string text, std::string color);