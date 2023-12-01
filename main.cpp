#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <Windows.h>

#include "classes/deck.hpp"
#include "classes/section.hpp"
#include "classes/column.hpp"
#include "classes/drawPile.hpp"
#include "classes/foundation.hpp"
#include "magic_enum/magic_enum.hpp"
#include "classes/game.hpp"
#include "gameLogic.hpp"

//Run
//g++ *.cpp classes/*.cpp -o main && ./main
int main(){
	std::cout << std::boolalpha;

	int const tablueColumns = 7;
	int const drawDeck = 52-(tablueColumns*(tablueColumns+1)/2);

	//Deck
	Deck deck;
	deck.Shuffle();

	//Game Object
	Game game;

	//Sections
	game.drawSection->AddPile(new DrawPile(deck.GetRange(drawDeck)));
	game.drawSection->AddPile(new CardPile(std::vector<Card*>()));

	for (int i = 0; i < magic_enum::enum_count<CardSuit>(); i++){
		game.foundationSection->AddPile(new Foundation());
	}

	for (int i = 1; i <= tablueColumns; i++){
		game.tableuSection->AddPile(new Column(deck.GetRange(i)));
	}

	//Section links
	game.drawSection->LinkSurroundingSection(Direction(1,0), game.foundationSection);
	game.tableuSection->LinkSurroundingSection(Direction(0,1), game.tableuSection);
	game.tableuSection->LinkSurroundingSection(Direction(0,1), game.tableuSection);

	//Game Loop
	bool inGame = true;
	while (inGame){
		Update(&game);
		Render(&game);
	}

	return 0;
}