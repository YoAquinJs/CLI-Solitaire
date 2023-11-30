#include "cursor.hpp"

Cursor::Cursor(Section* section) : section(section), cardIndex(0), pileIndex(0) {}

void Cursor::Move(Direction direction){
	int newCard = cardIndex + direction.y;
	int newPile = pileIndex + direction.x;

	//If either index overflow
	if (newCard < 0 || newCard == GetPile()->Count() || newPile < 0 || newPile == section->Count()){
		Section* nextSection = section->GetSurroundingSection(direction);
		if (nextSection != nullptr){
			newCard = 0;
			newPile = 0;
			section = nextSection;
		}
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