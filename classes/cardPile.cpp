#include <vector>

#include "cardPile.hpp"

CardPile::CardPile(std::vector<Card*>* initialCards) : cards(initialCards) {}

CardPile::~CardPile(){
	delete cards;
}

void CardPile::AddCard(Card* card){
	cards->insert(cards->begin(), card);
}

bool CardPile::CanAddCard(Card* card){
	return true;
}

int CardPile::Count(){
	return cards->size();
}

bool CardPile::TryAddCard(Card* card){
	if (!CanAddCard(card))
		return false;
	
	AddCard(card);
	return true;
}

bool CardPile::MoveCard(CardPile* destination){
	if (!(destination->TryAddCard(GetAt(0))))
		return false;

	cards->erase(cards->begin());
	return true;
}

Card* CardPile::GetAt(unsigned int index){
	if (index >= Count())
		return nullptr;
	return cards->at(index);
}
