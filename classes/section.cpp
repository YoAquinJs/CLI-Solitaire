#include <iostream>

#include "cardPile.hpp"
#include "section.hpp"

Section::Section(const int count) : count(count) {
	for (int i = 0; i < count; i++){
		std::vector<Card*> emptyPile;
		piles.push_back(new CardPile(emptyPile));
	}
}

Section::~Section(){
	//Free used memory
	for (CardPile* pile : piles){
		delete[] pile;
	}
}

void Section::LinkSurroundingSection(Direction direction, Section* section){
	if(surroundingSections.find(direction) != surroundingSections.end()){
		std::cout << "Direction X: " << direction.x << " Y: " <<direction.y << " Already existed\n";
		return;
	}

	surroundingSections.insert({direction, section});
	direction.x *= -1;
	direction.y *= -1;
	section->surroundingSections.insert({direction, this});
}