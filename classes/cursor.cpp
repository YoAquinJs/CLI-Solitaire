#include <iostream>
#include "cursor.hpp"
#include "column.hpp"

Cursor::Cursor(Section* section, int index) : section(section), cardIndex(0), pileIndex(0), index(index) {}

void Cursor::Move(Direction direction){
	int newCard = cardIndex + direction.y;
	int newPile = pileIndex + direction.x;
	Section* nextSection;

	//If either index overflow
	if (Column* column = dynamic_cast<Column*>(GetPile())){
		if(newCard < 0 || newCard == GetPile()->Count() || newPile < 0 || newPile == section->Count()){
			nextSection = section->GetSurroundingSection(direction);
		}
	}else if (newCard != cardIndex || newPile < 0 || newPile == section->Count()){
		nextSection = section->GetSurroundingSection(direction);
	}

	if (nextSection != nullptr){
		newCard = 0;
		newPile = 0;
		section = nextSection;
	}else{
		newCard = cardIndex;
		newPile = pileIndex;
	}

	cardIndex = newCard;
	pileIndex = newPile;
}

CardPile* Cursor::GetPile(){
	return section->GetAt(pileIndex);
}

Card* Cursor::GetCard(){
	return GetPile()->GetAt(cardIndex);
}