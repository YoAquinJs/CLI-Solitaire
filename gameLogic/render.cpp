#include <string>
#include <iostream>
#include <cstdlib>

#include "../magic_enum/magic_enum.hpp"
#include "gameLogic.hpp"
#include "utils.hpp"

char SuitToChar(CardSuit suit){
	switch (suit){
	case CardSuit::CLUBS:
		return 'C';
		break;
	case CardSuit::HEARTS:
		return 'H';
		break;
	case CardSuit::DIAMONDS:
		return 'D';
		break;
	case CardSuit::SPADES:
		return 'S';
		break;
	default:
		return '\n';
		break;
	}
}

std::string CardPrint(Card* card){
	std::string print = "";
	int rank = magic_enum::enum_integer<CardRank>(card->GetRank());

	print += "|";
	print += SuitToChar(card->GetSuit());
	print += rank < 10 ? ' ' : '1';
	print += rank < 10 ? ('0'+rank) : '0';
	print += "|";

	return print;
}

void Render(Game* game){
	#ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

	ColorPrint("-------------Solitarie-------------", GREEN);
	if (game->state == GameState::START)
		return;

	PrintLine("");

	for (int j = 0; j < 14; j++){
		bool oneNotNull = false;
		std::string line = "";
		std::string topLine = "";

		for (int i = 0; i < 7; i++){
			Card* card = game->renderMatrix[i][j];
			if (card != nullptr){
				oneNotNull = true;

				if (!card->hidden &&(card->GetSuit() == CardSuit::HEARTS || card->GetSuit() == CardSuit::DIAMONDS)){
					line+=RED;
					topLine+=RED;
				}

				if (game->cursor1->GetCard() == card){
					topLine+=BLUE;
				}if (game->cursor1->locked && game->cursor2->GetCard() == card){
					topLine+=YELLOW;
				}

				topLine += " ___ ";
				if (card->hidden)
					line += "|###|";
				else
					line += CardPrint(card);
				
			}else if ((j==0 && i!=2) || j==1){
				topLine += " ___ ";
				line    += "|___|";
			}else{
				topLine += "     ";
				line += "     ";
			}

			line+=RESET;
			topLine+=RESET;
		}
		if (!oneNotNull)
			break;

		PrintLine(topLine);
		PrintLine(line);
	}

	PrintLine("\n");
}