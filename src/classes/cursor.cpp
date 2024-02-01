#include "game.hpp"
#include "piles.hpp"

Cursor::Cursor(Section* section , int pileIndex) : section(section), pile(section->GetAt(pileIndex)), cardIndex(0), locked(false) {}

void Cursor::SetIndexToZero(){
	cardIndex = 0;
}

void Cursor::Move(Direction direction, std::function<Section* (CardPile*)> getSection){
	int newCard = cardIndex + direction.y;

	bool offLimitCard = false;
	if (Column* column = dynamic_cast<Column*>(GetPile())){
		if(newCard < 0 || newCard >= column->Count())
			offLimitCard = true;
	}else if (newCard != cardIndex)
		offLimitCard = true;

	if(offLimitCard)
		newCard = cardIndex;

	if(offLimitCard || direction.x != 0){
		CardPile* nextPile = pile->GetLinkAt(direction);
		if(nextPile != nullptr){
			newCard = 0;
			pile = nextPile;

		}
	}

	section = getSection(pile);
	cardIndex = newCard;
}

int Cursor::GetIndex(){
	return cardIndex;
}

CardPile* Cursor::GetPile(){
	return pile;
}

Card* Cursor::GetCard(){
	return pile->GetAt(cardIndex);
}

Section* Cursor::GetSection(){
	return section;
}
