#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>

#include "../classes/foundation.hpp"
#include "../classes/column.hpp"
#include "gameLogic.hpp"
#include "utils.hpp"

void FillRenderMatrix(Game* game){
	//Empty space between draw section and foundation section
	game->renderMatrix[2][0] = nullptr;

	//Draw Section
	for (int i = 0; i < game->drawSection.Count(); i++){
		game->renderMatrix[i][0] = game->drawSection.GetAt(i)->GetAt(0);
	}

	//Foundation Section
	for (int i = 0; i < game->foundationSection.Count(); i++){
		game->renderMatrix[i+3][0] = game->foundationSection.GetAt(i)->GetAt(0);
	}

	//Tableu Section
	for (int i = 1; i < 14; i++){
		for (int j = 0; j < game->tableuSection.Count(); j++){
			Column* column = static_cast<Column*>(game->tableuSection.GetAt(j));
			game->renderMatrix[j][i] = game->tableuSection.GetAt(j)->GetAt(column->Count()-i);
		}
	}
}

void Update(Game* game){
	switch (game->state){
	case GameState::START:
			ColorPrint("PRESS ENTER TWICE TO START", GREEN);

    		std::cin.clear();
    		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    		std::cin.get();

			game->state = GameState::ONGAME;
			FillRenderMatrix(game);
		break;
	case GameState::ONGAME:
		{
			PrintLine("Cursor Directions (W) up | (S) down | (A) left | (D) rigth)");
			PrintLine("SPACE Cursor Select ");
			ColorPrint("  Press a Key ", BLUE);

			std::string rawInput;
			std::cin >> rawInput;
			if (rawInput.length() != 1)
				break;

			char input = rawInput[0];

			FillRenderMatrix(game);
		}break;
	case GameState::WON:
			ColorPrint("YOU WON!!!", GREEN);
			ColorPrint("PRESS ENTER TWICE TO CLOSE THE PROGRAM", GREEN);

    		std::cin.clear();
    		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    		std::cin.get();

			exit(EXIT_SUCCESS);
		break;
	}
}