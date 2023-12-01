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
			PrintLine("Card suits are expressed as their initial leter");
			PrintLine("C clubs | H hearts | S spades | D diamonds");
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
			PrintLine("L to lock a position | K to unlock a position");
			PrintLine("J to try to perform a movement");
			ColorPrint("  Press a Key ", BLUE);

			std::string rawInput;
			std::cin >> rawInput;
			if (rawInput.size() != 1)
				return;

			char input = std::tolower(rawInput[0]);

			switch (input){
			case 'w':
				if (game->cursor1->locked){
					game->cursor2->Move(Direction(0,1));
					break;
				}
				game->cursor1->Move(Direction(0,1));
				break;
			case 's':
				if (game->cursor1->locked){
					game->cursor2->Move(Direction(0,-1));
					break;
				}
				game->cursor1->Move(Direction(0,-1));
				break;
			case 'a':
				if (game->cursor1->locked){
					game->cursor2->Move(Direction(-1,0));
					break;
				}
				game->cursor1->Move(Direction(-1,0));
				break;
			case 'd':
				if (game->cursor1->locked){
					game->cursor2->Move(Direction(1,0));
					break;
				}
				game->cursor1->Move(Direction(1,0));
				break;
			case 'l':
				if (game->cursor1->locked){
					ColorPrint("Invalid Action, cannot lock both cursors", RED);
					return;
				}
				game->cursor1->locked=true;
				break;
			case 'k':
				if (!game->cursor1->locked){
					ColorPrint("Invalid Action, cannot unlock cursor, when it's not locked", RED);
					return;
				}
				game->cursor1->locked=false;
				break;
			case 'j':
				if (!game->cursor1->locked){
					ColorPrint("Invalid Action, cursor 1 must be locked to perform action", RED);
					return;
				}
					
			default:
				ColorPrint("Invalid Input: " + input, RED);
				return;
			}

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