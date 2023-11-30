#include <vector>
#include <iostream>
#include <algorithm>
#include "drawPile.hpp"

DrawPile::DrawPile(std::vector<Card*> cards) : CardPile(cards){
	std::reverse(this->cards.begin(), this->cards.end());

	for (Card* card : this->cards){
		card->hidden = true;
	}
}

bool DrawPile::CanAddCard(Card* card){
	return false;
}

bool DrawPile::MoveCard(CardPile* destination){
	if (!(destination->TryAddCard(GetAt(0)))){
		return false;
	}
	GetAt(0)->hidden = false;
	cards.erase(cards.begin());
	return true;
}