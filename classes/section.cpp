#include <iostream>

#include "cardPile.hpp"
#include "section.hpp"

Section::Section() {
	//for (int i = 0; i < count; i++){
	//	std::vector<Card*> emptyPile;
	//	piles.push_back(new CardPile(emptyPile));
	//}
}

Section::~Section(){
	//Free used memory
	for (CardPile* pile : piles){
		delete[] pile;
	}
}

void Section::AddPile(CardPile* pile){
	piles.push_back(pile);
}


int Section::Count(){
	return piles.size();
}

void Section::LinkSurroundingSection(Direction direction, Section* surroundingSection){
	if(surroundingSections.find(direction) != surroundingSections.end()){
		std::cout << "Direction X: " << direction.x << " Y: " <<direction.y << " Already existed\n";
		return;
	}

	surroundingSections.insert({direction, surroundingSection});
	direction.x *= -1;
	direction.y *= -1;
	surroundingSection->surroundingSections.insert({direction, this});
}

Section* Section::GetSurroundingSection(Direction direction){
	auto surrounding = surroundingSections.find(direction);
	if (surrounding != surroundingSections.end())
		return surrounding->second;
	return nullptr;
}

CardPile* Section::GetAt(int index){
	return piles.at(index);
}