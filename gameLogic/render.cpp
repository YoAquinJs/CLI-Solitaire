#include <string>
#include <cstdlib>
#include <iostream>

#include "gameLogic.hpp"
#include "utils.hpp"

std::string CardContentPrint(Card* card, const int i, const int j);
std::string CardTopPrint(Card* card, Game* game, const int i, const int j);

void Render(Game* game, const int &moveCount){
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif

	std::string title = "SOLITAIRE!";
	std::string titleLine = "";
	for (int i = 0; i < (windowWidth-title.length())/2; i++){
		titleLine+= (i%2==0 ? RESET : RED)+"-";
	}
	titleLine+=RED+title;
	for (int i = 0; i < (windowWidth-title.length())/2; i++){
		titleLine+= (i%2==0 ? RESET : RED)+"-";
	}
	std::cout << titleLine+RESET << std::endl;

	switch (game->state){
		case GameState::START:
			PrintLine("Card suits are represented by their initial leter");
			PrintLine("C clubs | "+RED+"H hearts"+RESET+" | S spades | "+RED+"D diamonds"+RESET);
			ColorPrint("PRESS ENTER TWICE TO START", GREEN);
			break;
		case GameState::ONGAME:
			std::cout << std::endl;
			PrintLine("Movements:");
			PrintLine(std::to_string(moveCount));
			
			std::cout << GREEN << "              Draw                 Foundation               " << RESET << std::endl;
			for (int j = 0; j < 14; j++){//Row
				bool oneNotNull = false;
				std::string line = "";
				std::string topLine = "";

				if(j==1){
					std::cout << std::endl;
					ColorPrint("tableau", GREEN);
				}

				for (int i = 0; i < 7; i++){//Column
					Card* card = game->renderMatrix[i][j];
					if (card != nullptr)
						oneNotNull = true;

					line+=" ";
					line+=CardContentPrint(card, i, j);
					line+=RESET;

					topLine+=" ";
					topLine+=CardTopPrint(card, game, i, j);
					topLine+=RESET;
				}
				if (!oneNotNull)
					break;

				PrintLine(topLine);
				PrintLine(line);
			}

			std::cout << std::endl << std::endl;

			PrintLine("Cursor Directions");
			PrintLine("(W) up | (S) down | (A) left | (D) rigth");
			PrintLine("Commands");
			PrintLine("(L) lock the cursor | (K) unlock the cursor");
			PrintLine(BLUE+"blue"+RESET+" cursor is the origin and the "+YELLOW+"yellow"+RESET+" the destination");
			PrintLine("(J) to perform a movement");
			std::cout << std::endl;
			ColorPrint("Enter a Command or Direction", GREEN);
			break;
		case GameState::WON:
			PrintLine("YOU WON!!!");
			PrintLine("played " + std::to_string(moveCount) + " movements");
			ColorPrint("PRESS ENTER TWICE TO CLOSE THE PROGRAM", GREEN);
			break;
	}
}


std::string CardContentPrint(Card* card, const int i, const int j){
	std::string print = "";

	if (card == nullptr){
		if ((j==0 && i!=2) || j==1)
			print = "|___|";
		else
			print = "     ";
	}
	else if (card->hidden == true)
		print = "|###|";
	else{
		if (card->GetSuit() == CardSuit::HEARTS || card->GetSuit() == CardSuit::DIAMONDS)
			print+=RED;
		print += "|";
		print += card->SuitToChar();
		print += card->RankToStr();
		print += "|";
	}
	return print;
}

std::string CardTopPrint(Card* card, Game* game, const int i, const int j){
	std::string print = "";

	if (card != nullptr){
		if (!card->hidden &&(card->GetSuit() == CardSuit::HEARTS || card->GetSuit() == CardSuit::DIAMONDS))
			print+=RED;
		
		if (game->cursor1->GetCard() == card)
			print+=BLUE;
		if (game->cursor1->locked && game->cursor2->GetCard() == card)
			print+=YELLOW;
		
		print += " ___ ";
	}else if ((j==0 && i!=2) || j==1){
		if ((j==0 && game->cursor1->GetSection() == &(game->drawSection) && game->cursor1->GetPile() == game->drawSection.GetAt(i)) ||
			(j==0 && game->cursor1->GetSection() == &(game->foundationSection) && game->cursor1->GetPile() == game->foundationSection.GetAt(i-3)) ||
			(j==1 && game->cursor1->GetSection() == &(game->tableauSection) && game->cursor1->GetPile() == game->tableauSection.GetAt(i)))
				print+=BLUE;
		if (game->cursor1->locked){
			if ((j==0 && game->cursor2->GetSection() == &(game->drawSection) && game->cursor2->GetPile() == game->drawSection.GetAt(i)) ||
				(j==0 && game->cursor2->GetSection() == &(game->foundationSection) && game->cursor2->GetPile() == game->foundationSection.GetAt(i-3)) ||
				(j==1 && game->cursor2->GetSection() == &(game->tableauSection) && game->cursor2->GetPile() == game->tableauSection.GetAt(i)))
					print+=YELLOW;
		}
		print += " ___ ";
	}else
		print += "     ";

	return print;
}
