#include <string>
#include <iostream>
#include <cstdlib>

#include "../magic_enum/magic_enum.hpp"
#include "gameLogic.hpp"
#include "utils.hpp"

char SuitToChar(CardSuit suit){
	switch (suit){
	case CardSuit::CLUBS:
		return '\u2663';
		break;
	case CardSuit::HEARTS:
		return '\u2665';
		break;
	case CardSuit::DIAMONDS:
		return '\u2666';
		break;
	case CardSuit::SPADES:
		return '\u2660';
		break;
	default:
		return '\n';
		break;
	}
}

void Render(Game* game){
	#ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

	ColorPrint("--------------------------Solitarie--------------------------", GREEN);
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

				if (card->hidden){
					line += "|▒▒▒|";
					topLine += " ___ ";
					continue;
				}

				CardSuit suit = card->GetSuit();
				int rank = magic_enum::enum_integer<CardRank>(card->GetRank());
				if (suit == CardSuit::HEARTS || suit == CardSuit::DIAMONDS){
					line+=RED;
					topLine+=RED;
				}
				topLine += " ___ ";
				line += "|";
				line += SuitToChar(suit);
				line += rank < 10 ? ' ' : '1';
				line += rank < 10 ? ('0'+rank) : '0';
				line += "|";

				line+=RESET;
				topLine+=RESET;
				continue;
			}
			line += "     ";
			topLine += "     ";
		}
		if (!oneNotNull)
			break;

		PrintLine(topLine);
		PrintLine(line);
	}

	PrintLine("");
}