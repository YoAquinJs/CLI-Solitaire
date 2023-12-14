#include <iostream>

#include "cursor.hpp"
#include "column.hpp"

Cursor::Cursor(Section* section) : section(section), cardIndex(0), pileIndex(0), locked(false) {}

void Cursor::Move(Direction direction){
	int newCard = cardIndex + direction.y;
	int newPile = pileIndex + direction.x;
	
	bool offLimitCard = false;
	if (Column* column = dynamic_cast<Column*>(GetPile())){
		if(newCard < 0 || newCard == column->Count())
			offLimitCard = true;
	}else if (newCard != cardIndex)
		offLimitCard = true;

	bool offLimitPile = newPile < 0 || newPile == section->Count();
	
	Section* nextSection = nullptr;
	if(offLimitCard){
		nextSection = section->GetSurroundingSection(direction);
		newCard = cardIndex;
	}
	if(offLimitPile){
		nextSection = section->GetSurroundingSection(direction);
		newPile = pileIndex;
	}

	if (newPile != pileIndex)
		newCard = 0;

	if (nextSection != nullptr){
		newCard = 0;
		newPile = 0;
		section = nextSection;
	}

	pileIndex = newPile;
	cardIndex = newCard;
}

int Cursor::GetIndex(){
	return cardIndex;	
}

Section* Cursor::GetSection(){
	return section;
}

CardPile* Cursor::GetPile(){
	return section->GetAt(pileIndex);
}

Card* Cursor::GetCard(){
	return GetPile()->GetAt(cardIndex);
}
