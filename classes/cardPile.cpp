#include <vector>
#include "cardPile.hpp"

void CardPile::AddCard(Card* card){
	cards.insert(cards.begin(), card);
}

bool CardPile::CanAddCard(Card* card){
	return true;
}

CardPile::CardPile(std::vector<Card*> cards) : cards(cards) {}

int CardPile::Count(){
	return cards.size();
}

bool CardPile::TryAddCard(Card* card){
	if (!CanAddCard(card))
		return false;
	
	AddCard(card);
	return true;
}

bool CardPile::MoveCard(CardPile* destination){
	if (!(destination->TryAddCard(GetAt(0)))){
		return false;
	}
	cards.erase(cards.begin());
	return true;
}

Card* CardPile::GetAt(unsigned int index){
	return cards.at(index);
}