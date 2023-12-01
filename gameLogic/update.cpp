#include <string>
#include <iostream>
#include <limits>

#include "gameLogic.hpp"
#include "utils.hpp"

void Update(Game* game){
	if (game->state == GameState::START){
		ColorPrint("PRESS ENTER TWICE TO START", GREEN);

    	std::cin.clear();
    	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    	std::cin.get();

		game->state = GameState::ONGAME;
		return;
	}

	PrintLine("Cursor Directions (W up | S down | A left | D rigth)");
	PrintLine("SPACE Cursor Select ");
	ColorPrint("+Press a Key ", BLUE);

	std::string rawInput;
	std::cin >> rawInput;
	if (rawInput.length() != 1)
		return;

	char input = rawInput[0];
}