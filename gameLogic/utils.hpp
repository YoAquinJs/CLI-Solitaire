#pragma once

#include <string>
#include <iostream>

#include "classes/card.hpp"

const std::string RESET  = "\033[0m";
const std::string RED    = "\033[31m";
const std::string GREEN  = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE   = "\033[34m";
const std::string COLORS[] = {RESET, RED, GREEN, YELLOW, BLUE};

const int windowWidth = 60;

int StringColorExcludingLength(const std::string& str);

void PrintLine(const std::string& text, bool endLine=true);
void ColorPrint(const std::string& text, const std::string& color, bool endLine=true);
