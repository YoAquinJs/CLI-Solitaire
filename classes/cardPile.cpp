#include <vector>
#include "cardPile.hpp"

void CardPile::AddCard(Card* card){
	cards.insert(cards.begin(), card);
}
bool CardPile::CanAddCard(Card* card){
	return true;
}

CardPile::CardPile(std::vector<Card*> cards) : cards(cards) {}

bool CardPile::TryAddCard(Card* card){
	if (!CanAddCard(card))
		return false;
	
	AddCard(card);
	return true;
}

void CardPile::RemoveLast(){
	cards.erase(cards.begin());
}

Card* CardPile::GetLast(){
	return cards.front();
}