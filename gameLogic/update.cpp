#include <string>
#include <limits>
#include <cstdlib>

#include "../classes/foundation.hpp"
#include "../classes/drawPile.hpp"
#include "../classes/column.hpp"
#include "gameLogic.hpp"
#include "utils.hpp"

void WaitForEnter();
void FillRenderMatrix(Game* game);
bool WonGame(Game* game);
void PerformAction(Game* game, char input, int drawDeck, int &moveCount);

void Update(Game* game, int drawDeckSize, int &moveCount){
	switch (game->state){
		case GameState::START:
			WaitForEnter();

			game->state = GameState::ONGAME;
			FillRenderMatrix(game);
			break;
		case GameState::ONGAME:
		{
			std::string rawInput;
			std::cin >> rawInput;

			for (char command: rawInput){
				PerformAction(game, std::tolower(command), drawDeckSize, moveCount);
				if (WonGame(game)){
					game->state = GameState::WON;
					break;
				}
			}

			FillRenderMatrix(game);
		}break;
		case GameState::WON:
			WaitForEnter();

			game->state = GameState::START;
			break;
	}
}


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
		for (int j = 0; j < game->tableauSection.Count(); j++){
			Column* column = static_cast<Column*>(game->tableauSection.GetAt(j));
			game->renderMatrix[j][i] = game->tableauSection.GetAt(j)->GetAt(column->Count()-i);
		}
	}
}

void PerformAction(Game* game, char input, int drawDeckSize, int &moveCount){
	auto getSectionFunc = [&game](CardPile* pile) {
		return game->GetPileSection(pile);
	};

	switch (input){
		case 'w':
			if (game->cursor1->locked)
				game->cursor2->Move(Direction(0,1), getSectionFunc);
			else
				game->cursor1->Move(Direction(0,1), getSectionFunc);
			break;
		case 's':
			if (game->cursor1->locked)
				game->cursor2->Move(Direction(0,-1), getSectionFunc);
			else
				game->cursor1->Move(Direction(0,-1), getSectionFunc);
			break;
		case 'a':
			if (game->cursor1->locked)
				game->cursor2->Move(Direction(-1,0), getSectionFunc);
			else
				game->cursor1->Move(Direction(-1,0), getSectionFunc);
			break;
		case 'd':
			if (game->cursor1->locked)
				game->cursor2->Move(Direction(1,0), getSectionFunc);
			else
				game->cursor1->Move(Direction(1,0), getSectionFunc);
			break;

		case 'k':
			if (!game->cursor1->locked){
				game->cursor1->locked=true;
				game->cursor2->locked=false;
			}else
				game->cursor1->locked=false;
				game->cursor2->locked=true;
			break;

		case 'j':
			//Draw pile Interactions
			if (!game->cursor1->locked){
				if (game->cursor1->GetPile() != game->drawSection.GetAt(0))
					break;

				DrawPile* drawPile = dynamic_cast<DrawPile*>(game->drawSection.GetAt(0));
				if (!drawPile->MoveCard(game->drawSection.GetAt(1))){
					for (int i = 0; i < drawDeckSize; i++){
						std::cout << game->drawSection.GetAt(1)->MoveCard(drawPile) <<std::endl;
						std::cout << game->drawSection.GetAt(1)->Count() <<"\n";
					}
					drawPile->InitPile();
				}

				moveCount++;
				break;
			}
			//Draw Pile-Foundation Iteraction
			if (game->cursor1->GetPile() == game->drawSection.GetAt(1) && game->cursor2->GetSection() == &game->foundationSection){
				if(game->cursor1->GetPile()->MoveCard(dynamic_cast<Foundation*>(game->cursor2->GetPile())))
					moveCount++;
				break;
			}
			//Draw Pile-Column Iteraction
			if (game->cursor1->GetPile() == game->drawSection.GetAt(1) && game->cursor2->GetSection() == &game->tableauSection){
				if(game->cursor2->GetIndex() != 0){
					ColorPrint("Can only move to the columns top card", RED);
					WaitForEnter();
					break;
				}

				if(game->cursor1->GetPile()->MoveCard(dynamic_cast<Column*>(game->cursor2->GetPile())))
					moveCount++;
				break;
			}
			//Column-Column Interaction
			if (game->cursor1->GetSection() == &game->tableauSection && game->cursor2->GetSection() == &game->tableauSection){
				if(game->cursor2->GetIndex() != 0){
					ColorPrint("Can only move to the columns top card", RED);
					WaitForEnter();
					break;
				}

				if(dynamic_cast<Column*>(game->cursor1->GetPile())->MoveSubColumn(game->cursor1->GetIndex(), dynamic_cast<Column*>(game->cursor2->GetPile()))){
					game->cursor1->SetIndexToZero();
					moveCount++;
				}
				break;
			}
			//Foundation-Column Interaction
			if (game->cursor1->GetSection() == &game->tableauSection && game->cursor2->GetSection() == &game->foundationSection){
				if(game->cursor1->GetIndex() != 0){
					ColorPrint("Can only move a single card to foundation", RED);
					WaitForEnter();
					break;
				}

				if(game->cursor1->GetPile()->MoveCard(dynamic_cast<Foundation*>(game->cursor2->GetPile())))
					moveCount++;
				break;
			}
			if (game->cursor1->GetSection() == &game->foundationSection && game->cursor2->GetSection() == &game->tableauSection){
				if(game->cursor2->GetIndex() != 0){
					ColorPrint("Can only move to the columns top card", RED);
					WaitForEnter();
					break;
				}

				if(game->cursor1->GetPile()->MoveCard(dynamic_cast<Column*>(game->cursor2->GetPile())))
					moveCount++;
				break;
			}
			break;

		default:
			std::string response = "Invalid Input: ";
			response += input;
			ColorPrint(response, RED);
			WaitForEnter();
			break;
		}
}

bool WonGame(Game* game){
	for (int i = 0; i < game->foundationSection.Count(); i++){
		if (game->foundationSection.GetAt(i)->Count() == 0 || game->foundationSection.GetAt(i)->GetAt(0)->GetRank() != CardRank::KING)
			return false;
	}

	return true;
}
