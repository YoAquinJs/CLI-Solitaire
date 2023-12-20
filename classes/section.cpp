#include <iostream>

#include "section.hpp"
#include "cardPile.hpp"

Section::Section() : piles(std::vector<CardPile*>()) {}

Section::~Section(){
	for (CardPile* pile : piles){
		delete pile;
	}
}

void Section::AddPile(CardPile* pile){
 	piles.push_back(pile);
}

int Section::Count(){
	return piles.size();
}

int Section::GetIndexOf(CardPile* pile){
	for(int i=0; i < piles.size(); i++){
		if (piles[i] == pile)
			return i;
	}

	return -1;//Not found
}

CardPile* Section::GetAt(int index){
	if (index >= Count() || index < 0)
		return nullptr;
	return piles.at(index);
}
