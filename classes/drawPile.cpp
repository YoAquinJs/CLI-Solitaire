#include <vector>
#include <iostream>
#include <algorithm>
#include "drawPile.hpp"

DrawPile::DrawPile(std::vector<Card*>* initialCards) : CardPile(initialCards){
	std::reverse(cards->begin(), cards->end());
	InitPile();
}

void DrawPile::InitPile(){
	for (Card* card : *cards){
		card->hidden = true;
	}
}

bool DrawPile::CanAddCard(Card* card){
	return true;
}

bool DrawPile::MoveCard(CardPile* destination){
	if (Count() == 0 || !(destination->TryAddCard(GetAt(0)))){
		return false;
	}
	GetAt(0)->hidden = false;
	cards->erase(cards->begin());
	return true;
}