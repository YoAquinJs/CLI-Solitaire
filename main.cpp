#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "classes/deck.hpp"
#include "classes/section.hpp"
#include "classes/column.hpp"
#include "classes/drawPile.hpp"
#include "classes/foundation.hpp"
#include "magic_enum/magic_enum.hpp"

//Run
//g++ *.cpp classes/*.cpp -o main && ./main
int main(){
	std::cout << "--------------------------Solitarie--------------------------\n";
	std::cout << std::boolalpha;

	int const tablueColumns = 7;
	int const drawDeck = 52-(tablueColumns*(tablueColumns+1)/2);

	//Deck
	Deck deck;
	deck.Shuffle();

	//Sections
	Section drawSection;
	drawSection.AddPile(new DrawPile(deck.GetRange(drawDeck)));
	drawSection.AddPile(new CardPile(std::vector<Card*>()));

	Section foundationSection;
	for (int i = 0; i < magic_enum::enum_count<CardSuit>(); i++){
		foundationSection.AddPile(new Foundation());
	}

	Section tableuSection;
	for (int i = 1; i <= tablueColumns; i++){
		tableuSection.AddPile(new Column(deck.GetRange(i)));
	}

	//Section links
	drawSection.LinkSurroundingSection(Direction(1,0), &foundationSection);
	tableuSection.LinkSurroundingSection(Direction(0,1), &tableuSection);
	tableuSection.LinkSurroundingSection(Direction(0,1), &tableuSection);

	return 0;
}