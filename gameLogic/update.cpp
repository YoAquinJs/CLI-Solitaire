#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>

#include "../classes/foundation.hpp"
#include "../classes/drawPile.hpp"
#include "../classes/column.hpp"
#include "gameLogic.hpp"
#include "utils.hpp"

void WaitForEnter(){
	std::cin.clear();	
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
}

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

void Update(Game* game, int drawDeck){
	switch (game->state){
	case GameState::START:
			PrintLine("Card suits are expressed as their initial leter");
			PrintLine("C clubs | H hearts | S spades | D diamonds");
			ColorPrint("PRESS ENTER TWICE TO START", GREEN);

    		WaitForEnter();

			game->state = GameState::ONGAME;
			FillRenderMatrix(game);
		break;
	case GameState::ONGAME:
	{
		PrintLine("Cursor Directions (W) up | (S) down | (A) left | (D) rigth)");
		PrintLine("L to lock the cursor in a position | K to unlock it");
		PrintLine("The blue cursor is the origin and the yellow the destination");
		PrintLine("J to perform a movement");
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
				WaitForEnter();
				return;
			}
			game->cursor1->locked=true;
			break;

		case 'k':
			if (!game->cursor1->locked){
				ColorPrint("Invalid Action, cannot unlock cursor, when it's not locked", RED);
	    		WaitForEnter();
				return;
			}
			game->cursor1->locked=false;
			break;

		case 'j':
			//Draw pile Interactions
			if (!game->cursor1->locked){
				if (!(game->cursor1->GetPile() == game->drawSection.GetAt(0)))
					break;

				DrawPile* drawPile = dynamic_cast<DrawPile*>(game->drawSection.GetAt(0));
				if (!drawPile->MoveCard(game->drawSection.GetAt(1))){
					for (int i = 0; i < drawDeck; i++){
						std::cout << game->drawSection.GetAt(1)->MoveCard(drawPile) <<std::endl;
						std::cout << game->drawSection.GetAt(1)->Count() <<"\n";
					}
					drawPile->InitPile();
				}
				break;
			}
			//Draw Pile-Column Iteraction
			if (game->cursor1->GetPile() == game->drawSection.GetAt(1) && game->cursor2->GetSection() == &game->tableuSection){
				game->cursor1->GetPile()->MoveCard(dynamic_cast<Column*>(game->cursor2->GetPile()));
				break;
			}
			//Draw Pile-Foundation Iteraction
			if (game->cursor1->GetPile() == game->drawSection.GetAt(1) && game->cursor2->GetSection() == &game->foundationSection){
				game->cursor1->GetPile()->MoveCard(dynamic_cast<Foundation*>(game->cursor2->GetPile()));
				break;
			}
			//Column-Column Interaction
			if (game->cursor1->GetSection() == &game->tableuSection && game->cursor1->GetSection() == &game->tableuSection){
				Column* destination = dynamic_cast<Column*>(game->cursor2->GetPile());
				dynamic_cast<Column*>(game->cursor1->GetPile())->MoveSubColumn(game->cursor1->GetIndex(), destination);
				break;
			}
			//Foundation-Column Interaction
			if (game->cursor1->GetSection() == &game->tableuSection && game->cursor2->GetSection() == &game->foundationSection){
				game->cursor1->GetPile()->MoveCard(dynamic_cast<Foundation*>(game->cursor2->GetPile()));
				break;
			}
			if (game->cursor1->GetSection() == &game->foundationSection && game->cursor2->GetSection() == &game->tableuSection){
				game->cursor1->GetPile()->MoveCard(dynamic_cast<Column*>(game->cursor2->GetPile()));
				break;
			}
			break;
				
		default:
			ColorPrint("Invalid Input: " + input, RED);
    		WaitForEnter();
			return;
		}
		
		bool won = true;
		for (int i = 0; i < game->foundationSection.Count(); i++){
			if (game->foundationSection.GetAt(i)->Count() == 0){
				won = false;
				break;
			}
			if (game->foundationSection.GetAt(i)->GetAt(0)->GetRank() != CardRank::KING){
				won = false;
				break;
			}
		}
		if (won){
			game->state = GameState::WON;
			break;
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